#include <iosfwd>
//authoring
#pragma once
#ifndef RATIONAL_RATIONAL_H_20220313
#define RATIONAL_RATIONAL_H_20220313

class Rational {
public:
	Rational() = default;
	Rational(const int num);
	Rational(const int num, const int den);
	int num = 0;
	int den = 1;

	const char sep = '/';

	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;


	Rational operator+(const Rational& other);
	Rational operator+(const int other);
	Rational operator+();
	Rational operator-(const Rational& other);
	Rational operator-(const int other);
	Rational operator-();
	Rational operator*(const Rational& other);
	Rational operator*(const int other);
	Rational& operator+=(const Rational& other);
	Rational& operator+=(const int other);
	Rational& operator-=(const Rational& other);
	Rational& operator-=(const int other);
	Rational& operator*=(const Rational& other);
	Rational& operator*=(const int other);
	Rational& operator/=(const Rational& other);
	Rational& operator/=(const int other);
	Rational operator/(const Rational& other);
	Rational operator/(const int other);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	int gcm(const int lhs, const int rhs);
	int gcd(const int lhs, const int rhs);
	void normalize(Rational& temp);
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}


#endif