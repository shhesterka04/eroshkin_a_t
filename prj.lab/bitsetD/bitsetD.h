#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
//authoring
#pragma once
#ifndef BITSET_BITSETD_H
#define BITSET_BITSETD_H

class BitsetD {
public:
	class BitHolder {
	public:
		friend class BitsetD;
		BitHolder& operator=(const bool rhs);
		BitHolder() = default;
		~BitHolder() = default;
		explicit BitHolder(int position, BitsetD& data);
		operator bool() const;
	private:
		uint32_t& hold;//ссылка на инт в котором будет меняться бит
		uint32_t bit_position;//позиция внутри  hold
	};

	explicit BitsetD(const uint32_t size = 0,
		const bool filler = false);

	BitsetD(const BitsetD& copy);
	explicit BitsetD(const std::string& convert);

	BitsetD& operator=(const BitsetD& rhs);
	BitsetD& operator&=(const BitsetD& rhs);
	BitsetD& operator|=(const BitsetD& rhs);
	BitsetD& operator^=(const BitsetD& rhs);
	BitsetD& operator<<=(const uint32_t rhs);
	BitsetD& operator>>=(const uint32_t rhs);

	~BitsetD() = default;
	bool operator==(const BitsetD& rhs) const;
	bool operator!=(const BitsetD& rhs) const;

	BitsetD operator~() const;
	BitsetD operator&(const BitsetD& rhs) const;
	BitsetD operator|(const BitsetD& rhs) const;
	BitsetD operator^(const BitsetD& rhs) const;
	BitsetD operator<<(const uint32_t rhs) const;
	BitsetD operator>>(const uint32_t rhs) const;

	bool operator[](const uint32_t position) const;
	BitHolder operator[](const uint32_t position);

	uint32_t size() const;
	void resize(const uint32_t size, const bool filler = false);

private:
	static const int size_of_type = 8 * sizeof(uint32_t);
	std::vector<uint32_t> data;
	uint32_t datasize;

};
std::ostream& operator<<(std::ostream& ostream,
	const BitsetD& data);
std::istream& operator>>(std::istream& istream, BitsetD& data);

#endif