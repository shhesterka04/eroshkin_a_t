#include <bitsetD/bitsetD.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

BitsetD::BitsetD(const BitsetD& copy) :
	data(copy.data),
	datasize(copy.datasize) {

}; // ��� ������������� ������� �� ����� �� ���������� 2 �������� ���������: ������ � �������� �������

BitsetD::BitsetD(const uint32_t size, const bool filler) :
	data(std::vector<uint32_t>()),
	datasize(0)
{
	if (size < 0)
		throw std::logic_error("Bitset error: sizes of constractor is nagative");
	data = std::vector<uint32_t>((size + size_of_type - 1) / size_of_type); //!!!
	if (filler == true)
		fill(data.begin(), data.end(), uint32_t(-1));
	datasize = size;
};

BitsetD::BitHolder& BitsetD::BitHolder::operator=(const bool rhs) {
	uint32_t x = (uint32_t(1) << (*this).bit_position);
	if (rhs == true)
		(*this).hold |= x;
	else
		(*this).hold &= ~(x);
	return *this;
};

BitsetD::BitHolder::operator bool() const {
	return hold >> (bit_position % size_of_type) & 1;
}

BitsetD::BitHolder BitsetD::operator[](const uint32_t position) {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("BitsetD error: index_eror");
	return BitHolder(position, (*this));// ���� ��� ��, ��������� ���������
};

BitsetD::BitHolder::BitHolder(int position, BitsetD& bitset) :
	hold(bitset.data[position / size_of_type]),
	bit_position(position% size_of_type)
{}; // ������������� ����������: ����������� ���, ������� ����

BitsetD& BitsetD::operator=(const BitsetD& rhs) = default;

BitsetD& BitsetD::operator&=(const BitsetD& rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] &= rhs.data[i];
	}
	return *this;
};
BitsetD& BitsetD::operator|=(const BitsetD& rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] |= rhs.data[i];
	}
	return *this;
};
BitsetD& BitsetD::operator^=(const BitsetD& rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] ^= rhs.data[i];
	}
	return *this;
};
BitsetD& BitsetD::operator<<=(const uint32_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = 0; i < rhs; i++)
		(*this)[i] = 0;
	return *this;
};
BitsetD& BitsetD::operator>>=(const uint32_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = datasize - rhs; i < datasize; i++)
		(*this)[i] = 0;
	return *this;
}; //��� ��� ���������� ���� �� �������� �������, ������ ���� �� ������ �������, �������� �������� �������� �� rhs. �������
//�� �������� ��������. 

bool BitsetD::operator==(const BitsetD& rhs) const {
	if ((*this).size() != rhs.size())
		return false;

	for (int i = 0; i < rhs.size(); ++i)
		if ((*this)[i] != rhs[i])
			return false;
	return true;
};
bool BitsetD::operator!=(const BitsetD& rhs) const {
	return !((*this) == rhs);
};

BitsetD BitsetD::operator~() const {
	BitsetD tmp = *this;
	for (int i = 0; i < tmp.data.size(); ++i)
		tmp.data[i] = ~tmp.data[i];
	return tmp;
};
BitsetD BitsetD::operator&(const BitsetD& rhs) const {
	BitsetD tmp = *this;
	tmp &= rhs;
	return tmp;
};
BitsetD BitsetD::operator|(const BitsetD& rhs) const {
	BitsetD tmp = *this;
	tmp |= rhs;
	return tmp;
};
BitsetD BitsetD::operator^(const BitsetD& rhs) const {
	BitsetD tmp = *this;
	tmp ^= rhs;
	return tmp;
};
BitsetD BitsetD::operator<<(const uint32_t rhs) const {
	BitsetD tmp = *this;
	tmp <<= rhs;
	return tmp;
};
BitsetD BitsetD::operator>>(const uint32_t rhs) const {
	BitsetD tmp = *this;
	tmp >>= rhs;
	return tmp;
};

bool BitsetD::operator[](const uint32_t position) const {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("Bitset error: index_eror");
	return (data[position / size_of_type] >> position % size_of_type) & 1;
};

uint32_t BitsetD::size() const { return (*this).datasize; };

void BitsetD::resize(const uint32_t size, const bool filler) {
	uint32_t pred_size = uint32_t((*this).size());
	uint32_t new_size_of_data = (size + size_of_type - 1) / size_of_type;
	data.resize(new_size_of_data);
	datasize = size;
	if (pred_size < size)
		for (int i = pred_size; i < size; ++i)
			(*this)[i] = bool(filler);

}; //��������� ������ ������ �������, � ������� ����� ������ �������. ��������� ������ � ������ ���� ������.

BitsetD::BitsetD(const std::string & convert)
	:data(std::vector<uint32_t>(0)), datasize(0)
{
	BitsetD tmp(convert.size());
	for (int i = 0; i < convert.size(); i++)
		tmp[convert.size() - 1 - i] = ('1' == convert[i]);

	data = tmp.data;
	datasize = tmp.size();
} 

std::ostream& operator<<(std::ostream & ostream, const BitsetD & data) {
	for (int i = data.size() - 1; i >= 0; i--)
		ostream << data[i];
	return ostream; // ������� ������ �����
};
std::istream& operator>>(std::istream & istream, BitsetD & data) {
	std::string buff("");
	while (istream.peek() == '0' || istream.peek() == '1') {
		buff.push_back(istream.get());
	}
	if (buff.size() > 0) {
		data = BitsetD(buff);
	}
	else {
		istream.setstate(std::ios_base::failbit);
	}
	return istream;
};