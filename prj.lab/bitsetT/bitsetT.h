#ifndef BITSET_BITSET_H_20220403
#define BITSET_BITSET_H_20220403
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//authoring
#pragma once


//using T = uint32_t;
template <class T>
class BitsetT {
public:
	class BitHolder {
	public:
		friend class BitsetT;
		BitHolder& operator=(const bool rhs);
		BitHolder() = default;
		~BitHolder() = default;
		explicit BitHolder(int position, BitsetT& data);
		operator bool() const;
	private:
		T& hold;//������ �� ��� � ������� ����� �������� ���
		T bit_position;//������� ������  hold
	};

	explicit BitsetT(const int64_t size = 0,
		const bool filler = false);

	BitsetT(const BitsetT& copy);
	explicit BitsetT(const std::string& convert);

	BitsetT<T>& operator=(const BitsetT& rhs);
	BitsetT<T>& operator&=(const BitsetT& rhs);
	BitsetT& operator|=(const BitsetT& rhs);
	BitsetT& operator^=(const BitsetT& rhs);
	BitsetT& operator<<=(const int64_t rhs);
	BitsetT& operator>>=(const int64_t rhs);

	~BitsetT() = default;
	bool operator==(const BitsetT& rhs) const;
	bool operator!=(const BitsetT& rhs) const;

	BitsetT operator~() const;
	BitsetT operator&(const BitsetT& rhs) const;
	BitsetT operator|(const BitsetT& rhs) const;
	BitsetT operator^(const BitsetT& rhs) const;
	BitsetT operator<<(const T rhs) const;
	BitsetT operator>>(const T rhs) const;

	bool operator[](const T position) const;
	BitHolder operator[](const T position);

	int64_t size() const;
	void resize(const int64_t size, const bool filler = false);
private:
	static const int size_of_type = 8 * sizeof(T);//������ ���� ������� �� ���������� � �����
	std::vector<T> data;
	int64_t datasize;

};

template <class T>
std::ostream& operator<<(std::ostream& ostream,
	const BitsetT<T>& data);
template <class T>
std::istream& operator>>(std::istream& istream, BitsetT<T>& data);


template <class T>
BitsetT<T>::BitsetT(const BitsetT<T>& copy) :
	data(copy.data),
	datasize(copy.datasize) {

}; // ��� ������������� ������� �� ����� �� ���������� 2 �������� ���������: ������ � �������� �������

template <class T>
BitsetT<T>::BitsetT(const int64_t size, const bool filler) :
	data(std::vector<T>()),
	datasize(0)
{
	if (size < 0)
		throw std::logic_error("BitsetT error: sizes of constractor is nagative");
	data = std::vector<T>((size + size_of_type - 1) / size_of_type); //!!!
	if (filler == true)
		fill(data.begin(), data.end(), ~T(0)); //���� ���� ����� 1, �� ��������� ������ -1 ������ -1
	datasize = size;
};

template <class T>
typename BitsetT<T>::BitHolder& BitsetT<T>::BitHolder::operator=(const bool rhs) {
	T x = (T(1) << (*this).bit_position);
	if (rhs == true)
		(*this).hold |= x;
	else
		(*this).hold &= ~(x);
	return *this;
};

template <class T>
BitsetT<T>::BitHolder::operator bool() const {
	return hold >> (bit_position % size_of_type) & 1;
}

template <class T>
typename BitsetT<T>::BitHolder BitsetT<T>::operator[](const T position) {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("BitsetT error: index_eror");
	return BitHolder(position, (*this));// ���� ��� ��, ��������� ���������
}

template <class T>
BitsetT<T>::BitHolder::BitHolder(int position, BitsetT<T>& bitset) :
	hold(bitset.data[position / size_of_type]),
	bit_position(position% size_of_type)
{}; // ������������� ����������: ����������� ���, ������� ����

template <class T>
BitsetT<T>& BitsetT<T>::operator=(const BitsetT<T>& rhs) = default;

template <class T>
BitsetT<T>& BitsetT<T>::operator&=(const BitsetT<T>&rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("BitsetT error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] &= rhs.data[i];
	}
	return *this;
};

template <class T>
BitsetT<T>& BitsetT<T>::operator|=(const BitsetT<T>&rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("BitsetT error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] |= rhs.data[i];
	}
	return *this;
};

template <class T>
BitsetT<T>& BitsetT<T>::operator^=(const BitsetT<T>&rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("BitsetT error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] ^= rhs.data[i];
	}
	return *this;
};


template <class T>
BitsetT<T>& BitsetT<T>::operator<<=(const int64_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = 0; i < rhs; i++)
		(*this)[i] = 0;
	return *this;
};
template <class T>
BitsetT<T>& BitsetT<T>::operator>>=(const int64_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = datasize - rhs; i < datasize; i++)
		(*this)[i] = 0;
	return *this;
}; //��� ��� ���������� ���� �� �������� �������, ������ ���� �� ������ �������, �������� �������� �������� �� rhs. �������
//�� �������� ��������. 

template <class T>
bool BitsetT<T>::operator==(const BitsetT<T>&rhs) const {
	if ((*this).size() != rhs.size())
		return false;

	for (int i = 0; i < rhs.size(); ++i)
		if ((*this)[i] != rhs[i])
			return false;
	return true;
};
template <class T>
bool BitsetT<T>::operator!=(const BitsetT<T>&rhs) const {
	return !((*this) == rhs);
};

template <class T>
BitsetT<T> BitsetT<T>::operator~() const {
	BitsetT tmp = *this;
	for (int i = 0; i < tmp.data.size(); ++i)
		tmp.data[i] = ~tmp.data[i];
	return tmp;
};

template <class T>
BitsetT<T> BitsetT<T>::operator&(const BitsetT<T>&rhs) const {
	BitsetT tmp = *this;
	tmp &= rhs;
	return tmp;
};

template <class T>
BitsetT<T> BitsetT<T>::operator|(const BitsetT<T>&rhs) const {
	BitsetT tmp = *this;
	tmp |= rhs;
	return tmp;
};

template <class T>
BitsetT<T> BitsetT<T>::operator^(const BitsetT<T>&rhs) const {
	BitsetT tmp = *this;
	tmp ^= rhs;
	return tmp;
};

template <class T>
BitsetT<T> BitsetT<T>::operator<<(const T rhs) const {
	BitsetT tmp = *this;
	tmp <<= rhs;
	return tmp;
};

template <class T>
BitsetT<T> BitsetT<T>::operator>>(const T rhs) const {
	BitsetT tmp = *this;
	tmp >>= rhs;
	return tmp;
};

template <class T>
bool BitsetT<T>::operator[](const T position) const {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("BitsetT error: index_eror");
	return (data[position / size_of_type] >> position % size_of_type) & 1;
};

template <class T>
int64_t BitsetT<T>::size() const { return (*this).datasize; };

template <class T>
void BitsetT<T>::resize(const int64_t size, const bool filler) {
	int64_t pred_size = int64_t((*this).size());
	int64_t new_size_of_data = (size + size_of_type - 1) / size_of_type;
	data.resize(new_size_of_data);
	datasize = size;
	if (pred_size < size)
		for (int i = pred_size; i < size; ++i)
			(*this)[i] = bool(filler);

}; //��������� ������ ������ �������, � ������� ����� ������ �������. ��������� ������ � ������ ���� ������.

template <class T>
BitsetT<T>::BitsetT(const std::string & convert)
	:data(std::vector<T>(0)), datasize(0)
{
	BitsetT tmp(convert.size());
	for (int i = 0; i < convert.size(); i++)
		tmp[convert.size() - 1 - i] = ('1' == convert[i]);

	data = tmp.data;
	datasize = tmp.size();
} //!

template <class T>
std::ostream& operator<<(std::ostream & ostream, const BitsetT<T>&data) {
	for (int i = data.size() - 1; i >= 0; i--)
		ostream << data[i];
	return ostream; // ������� ������ �����
};

template <class T>
std::istream& operator>>(std::istream & istream, BitsetT<T>&data) {
	std::string buff("");
	while (istream.peek() == '0' || istream.peek() == '1') {
		buff.push_back(istream.get());
	}
	if (buff.size() > 0) {
		data = BitsetT<T>(buff);
	}
	else {
		istream.setstate(std::ios_base::failbit);
	}
	return istream;
};

#endif