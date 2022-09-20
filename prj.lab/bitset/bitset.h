#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
//authoring
#pragma once
#ifndef BITSET_BITSET_H_20220403
#define BITSET_BITSET_H_20220403

class Bitset {
public:
	class BitHolder {
	public:
		friend class Bitset;
		BitHolder& operator=(const bool rhs);
		BitHolder() = default;
		~BitHolder() = default;
		explicit BitHolder(int position, Bitset& data);
		operator bool() const;
	private:
		uint32_t& hold;//ссылка на инт в котором будет меняться бит
		uint32_t bit_position;//позиция внутри  hold
	};

	explicit Bitset(const uint32_t size = 0,
		const bool filler = false);

	Bitset(const Bitset& copy);
	explicit Bitset(const std::string& convert);

	Bitset& operator=(const Bitset& rhs);
	Bitset& operator&=(const Bitset& rhs);
	Bitset& operator|=(const Bitset& rhs);
	Bitset& operator^=(const Bitset& rhs);
	Bitset& operator<<=(const uint32_t rhs);
	Bitset& operator>>=(const uint32_t rhs);

	~Bitset() = default;
	bool operator==(const Bitset& rhs) const;
	bool operator!=(const Bitset& rhs) const;

	Bitset operator~() const;
	Bitset operator&(const Bitset& rhs) const;
	Bitset operator|(const Bitset& rhs) const;
	Bitset operator^(const Bitset& rhs) const;
	Bitset operator<<(const uint32_t rhs) const;
	Bitset operator>>(const uint32_t rhs) const;

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
	const Bitset& data);
std::istream& operator>>(std::istream& istream, Bitset& data);

#endif