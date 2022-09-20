#include <bitset/bitset.h>
#include <iostream>
#include <sstream>
#include <string>

Bitset::Bitset(const Bitset& copy) :
	data(copy.data),
	datasize(copy.datasize) {

}; // При инициализации битсета по копии мы перенимаем 2 основных параметра: размер и хранимое битсета

Bitset::Bitset(const uint32_t size, const bool filler) :
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

Bitset::BitHolder& Bitset::BitHolder::operator=(const bool rhs) {
	uint32_t x = (uint32_t(1) << (*this).bit_position);
	if (rhs == true)
		(*this).hold |= x;
	else
		(*this).hold &= ~(x);
	return *this;
};

Bitset::BitHolder::operator bool() const {
	return hold >> (bit_position % size_of_type) & 1;
}

Bitset::BitHolder Bitset::operator[](const uint32_t position) {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("Bitset error: index_eror");
	return BitHolder(position, (*this));// Если все ок, возращает битхолдер
};

Bitset::BitHolder::BitHolder(int position, Bitset& bitset) :
	hold(bitset.data[position / size_of_type]),
	bit_position(position% size_of_type)
{}; // Инициализация битхолдера: присваиваем все, кратное биту

Bitset& Bitset::operator=(const Bitset& rhs) = default;

Bitset& Bitset::operator&=(const Bitset & rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] &= rhs.data[i];
	}
	return *this;
};
Bitset& Bitset::operator|=(const Bitset & rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] |= rhs.data[i];
	}
	return *this;
};
Bitset& Bitset::operator^=(const Bitset & rhs) {
	if ((*this).size() != rhs.size())
		throw std::logic_error("Bitset error: sizes of operands do not match");
	for (int i = 0; i < data.size(); i++) {
		data[i] ^= rhs.data[i];
	}
	return *this;
};
Bitset& Bitset::operator<<=(const uint32_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = 0; i < rhs; i++)
		(*this)[i] = 0;
	return *this;
};
Bitset& Bitset::operator>>=(const uint32_t rhs) {
	for (int i = datasize - 1; i > rhs; i--)
		(*this)[i] = bool((*this)[i - rhs]);

	for (int i = datasize - rhs; i < datasize; i++)
		(*this)[i] = 0;
	return *this;
}; //Так как индексация идет от старшего разряда, крутим цикл до начала вектора, выполнея смещение значений на rhs. Остатки
//от смешения зануляем. 

bool Bitset::operator==(const Bitset & rhs) const {
	if ((*this).size() != rhs.size())
		return false;

	for (int i = 0; i < rhs.size(); ++i)
		if ((*this)[i] != rhs[i])
			return false;
	return true;
};
bool Bitset::operator!=(const Bitset & rhs) const {
	return !((*this) == rhs);
};

Bitset Bitset::operator~() const {
	Bitset tmp = *this;
	for (int i = 0; i < tmp.data.size(); ++i)
		tmp.data[i] = ~tmp.data[i];
	return tmp;
};
Bitset Bitset::operator&(const Bitset & rhs) const {
	Bitset tmp = *this;
	tmp &= rhs;
	return tmp;
};
Bitset Bitset::operator|(const Bitset & rhs) const {
	Bitset tmp = *this;
	tmp |= rhs;
	return tmp;
};
Bitset Bitset::operator^(const Bitset & rhs) const {
	Bitset tmp = *this;
	tmp ^= rhs;
	return tmp;
};
Bitset Bitset::operator<<(const uint32_t rhs) const {
	Bitset tmp = *this;
	tmp <<= rhs;
	return tmp;
};
Bitset Bitset::operator>>(const uint32_t rhs) const {
	Bitset tmp = *this;
	tmp >>= rhs;
	return tmp;
};

bool Bitset::operator[](const uint32_t position) const {
	if (position < 0 || position >= (*this).size())
		throw std::logic_error("Bitset error: index_eror");
	return (data[position / size_of_type] >> position % size_of_type) & 1;
};

uint32_t Bitset::size() const { return (*this).datasize; };

void Bitset::resize(const uint32_t size, const bool filler) {
	uint32_t pred_size = uint32_t((*this).size());
	uint32_t new_size_of_data = (size + size_of_type - 1) / size_of_type;
	data.resize(new_size_of_data);
	datasize = size;
	if (pred_size < size)
		for (int i = pred_size; i < size; ++i)
			(*this)[i] = bool(filler);

}; //Сохраняем старый размер вектора, и создаем новый размер вектора. Расширяем вектор и вносим туда данные.

Bitset::Bitset(const std::string & convert)
	:data(std::vector<uint32_t>(0)), datasize(0)
{
	Bitset tmp(convert.size());
	for (int i = 0; i < convert.size(); i++)
		tmp[convert.size() - 1 - i] = ('1' == convert[i]);

	data = tmp.data;
	datasize = tmp.size();
} //!

std::ostream& operator<<(std::ostream & ostream, const Bitset & data) {
	for (int i = data.size() - 1; i >= 0; i--)
		ostream << data[i];
	return ostream; // Выводим каждый битик
};
std::istream& operator>>(std::istream & istream, Bitset & data) {
	std::string buff("");
	while (istream.peek() == '0' || istream.peek() == '1') {
		buff.push_back(istream.get());
	}
	if (buff.size() > 0) {
		data = Bitset(buff);
	}
	else {
		istream.setstate(std::ios_base::failbit);
	}
	return istream;
};