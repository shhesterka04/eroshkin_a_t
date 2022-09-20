#include <iosfwd>
//authoring
#pragma once
#ifndef COMPLEX_COMPLEX_H_20220309
#define COMPLEX_COMPLEX_H_20220309

struct Complex {
	Complex();
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); };

	Complex operator-();
	Complex& operator+() { return *this; }

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double& rhs);

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double& rhs);

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double& rhs);

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double& rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char lsc{ '{' };
	static const char rsc{ '}' };
	static const char sep{ ',' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator-(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rc) {
	return rc.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rc) {
	return rc.readFrom(istrm);
}

#endif