#include <rational/rational.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cctype>

int Rational::gcd(int lhs, int rhs) {
	lhs = abs(lhs);
	rhs = abs(rhs);
	if (lhs < rhs) {
		std::swap(lhs, rhs);
	}
	if (rhs == 0) {
		return lhs;
	}
	else {
		while (lhs % rhs != 0) {
			lhs = lhs % rhs;
			std::swap(lhs, rhs);
		}
		return rhs;
	}
};
int Rational::gcm(int lhs, int rhs) {
	return lhs * rhs / (gcd(lhs, rhs));
};

void Rational::normalize(Rational& temp) {
	if (den == 0)
		throw "Attempt to divide by zero!";
	int t = gcd(temp.den, temp.num);
	if ((temp.den < 0 && temp.num > 0) || (temp.den < 0 && temp.num < 0)) {
		temp.den *= -1;
		temp.num *= -1;
	}
	temp.den /= t;
	temp.num /= t;
};

bool Rational::operator==(const Rational& other) const { return num == other.num && den == other.den; }
bool Rational::operator!=(const Rational& other) const { return !operator==(other); }

Rational Rational:: operator+() { return *this; };
Rational Rational:: operator-() { 
	normalize(*this);
	num = -num;
	return *this;
};

Rational& Rational::operator+=(const Rational& other) {
	num = num * other.den + den * other.num;
	den = den * other.den;
	normalize(*this);
	return *this;
};
Rational& Rational::operator+=(const int other) {
	num = num + den * other;
	normalize(*this);
	return *this;
};
Rational& Rational::operator-=(const Rational& other) {
	num = num * other.den - den * other.num;
	den = den * other.den;
	normalize(*this);
	return *this;
};
Rational& Rational::operator-=(const int other) {
	num = num - den * other;
	normalize(*this);
	return *this;
};
Rational& Rational::operator/=(const Rational& other) {
	num = num * other.den;
	den = den * other.num;
	normalize(*this);
	return *this;
};
Rational& Rational::operator/=(const int other) {
	den = den * other;
	normalize(*this);
	return *this;
};
Rational& Rational::operator*=(const Rational& other) {
	num = num * other.num;
	den = den * other.den;
	normalize(*this);
	return *this;
};
Rational& Rational::operator*=(const int other) {
	num = num * other;
	normalize(*this);
	return *this;
};
Rational Rational::operator/(const Rational& other) {
	Rational temp = *this;
	temp /= other;
	normalize(*this);
	return temp;
};
Rational Rational::operator/(const int other) {
	Rational temp = *this;
	temp /= other;
	normalize(*this);
	return temp;
};

Rational Rational:: operator+(const Rational& other) {
	Rational temp = *this;
	temp += other;
	normalize(*this);
	return temp;
}

Rational Rational::operator+(const int other) {
	Rational temp = *this;
	temp += other;
	normalize(*this);
	return temp;
};

Rational Rational::operator-(const Rational& other) {
	Rational temp = *this;
	temp -= other;
	normalize(*this);
	return temp;
};
Rational Rational::operator-(const int other) {
	Rational temp = *this;
	temp -= other;
	normalize(*this);
	return temp;
};



Rational Rational::operator*(const Rational& other) {
	Rational temp = *this;
	temp *= other;
	normalize(*this);
	return temp;
};
Rational Rational::operator*(const int other) {
	Rational temp = *this;
	temp *= other;
	normalize(*this);
	return temp;
};


Rational::Rational(const int numerator, const int denominator) :
	num(numerator),
	den(denominator)
{
	normalize(*this);
};
Rational::Rational(const int numerator) :
	num(numerator),
	den(1)
{

}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num << sep << den;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {

	char frac('\0');
	int p_1(0);
	int q_1(0);
	char separator(0);

	istrm >> p_1;
	istrm.get(separator);
	if (!std::isdigit(istrm.peek())) {
		istrm >> q_1;
		istrm.setstate(std::ios_base::failbit);
	}
	else {
		istrm >> q_1;
	}
	if (istrm.good() || istrm.rdstate() == std::ios_base::eofbit) {
		if (separator == Rational::sep) {
			(*this).den = q_1;
			(*this).num = p_1;
			normalize(*this);
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
};
