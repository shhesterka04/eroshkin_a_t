#ifndef BITSETI_BITSETI_H_20220427
#define BITSETI_BITSETI_H_20220427

#include <cstdint>
#include <vector>
#include <iostream>

using T = uint64_t;

class BitsetI {
public:
	BitsetI() = default;
	virtual ~BitsetI() = default;
	virtual std::ostream& WriteTo(std::ostream& ostream) const = 0;
	virtual std::istream& ReadFrom(std::istream& istream) = 0;
};

#endif
