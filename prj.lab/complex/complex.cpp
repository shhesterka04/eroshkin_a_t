#include <complex/complex.h>
#include <iostream>
#include <sstream>
#include <limits>

Complex::Complex()
	:Complex(0.0, 0.0)
{
}

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real),
	im(imaginary)
{
}

bool Complex::operator==(const Complex& rhs) const {
	return (std::abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon()
		&& std::abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon());
}

Complex Complex::operator-() {
	re = -re;
	im = -im;
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator+=(const double& rhs) {
	re += rhs;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex& Complex::operator-=(const double& rhs) {
	re -= rhs;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	double temp = re;
	re = re * rhs.re - im * rhs.im;
	im = temp * rhs.im + im * rhs.re;
	return *this;
}
Complex& Complex::operator*=(const double& rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	double tempre = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	double tempim = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	if (rhs.re * rhs.re + rhs.im * rhs.im == 0)
		throw std::invalid_argument("������: ������� ������� �� ����");
	re = tempre;
	im = tempim;
	return *this;
}
Complex& Complex::operator/=(const double& rhs) {
	if (rhs == 0)
		throw std::invalid_argument("������: ������� ������� �� ����");
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex temp;
	temp += lhs;
	temp += rhs;
	return temp;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex temp;
	temp += lhs;
	temp -= rhs;
	return temp;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex temp;
	temp += lhs;
	temp *= rhs;
	return temp;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex temp = lhs;
	temp /= rhs;
	return temp;
}

Complex operator+(const Complex& lhs, const double& rhs) {
	Complex temp;
	temp += lhs;
	temp += rhs;
	return temp;
}

Complex operator-(const Complex& lhs, const double& rhs) {
	Complex temp;
	temp += lhs;
	temp -= rhs;
	return temp;
}

Complex operator*(const Complex& lhs, const double& rhs) {
	Complex temp;
	temp += lhs;
	temp *= rhs;
	return temp;
}

Complex operator/(const Complex& lhs, const double& rhs) {
	Complex temp = lhs;
	temp /= rhs;
	return temp;
}

Complex operator+(const double& lhs, const Complex& rhs) {
	return rhs + lhs;
}

Complex operator-(const double& lhs, const Complex& rhs) {
	return (-1) * rhs + lhs;
}

Complex operator*(const double& lhs, const Complex& rhs) {
	return rhs * lhs;
}

Complex operator/(const double& lhs, const Complex& rhs) {
	Complex temp(lhs);
	temp /= rhs;
	return temp;
}


std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << lsc << re << sep << im << rsc;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& is)
{
	char leftBrace(0);
	char comma(0);
	char rightBrace(0);
	double real(0.0);
	double imaganary(0.0);
	is >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (is.good()) {
		if ((Complex::lsc == leftBrace) && (Complex::rsc == rightBrace) && (Complex::sep == comma)) {
			re = real;
			im = imaganary;
		}
		else {
			is.setstate(std::ios_base::failbit);
		}
	}
	return is;
}


