#include <complex/complex.h>
#include <iostream>
#include <sstream>

int main() {
	Complex a(3, 5);
	Complex b(2, -1);
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "a * b = " << a * b << "\n";
	std::cout << "a + b = " << a + b << "\n";
	std::cout << "a - b = " << a - b << "\n";
	std::cout << "a / b = " << a / b << "\n";
	std::cout << "a + 4 = " << a + 4 << "\n";
	std::cout << "4 + a = " << 4 + a << "\n";
	std::cout << "a * 2 = " << a * 2 << "\n";
	std::cout << "a / 4 = " << a / 4 << "\n";
	std::cout << "+a = " << +a << "\n";
	std::cout << "-a = " << -a << "\n";
	if (a == Complex(3, 5))
		std::cout << "a == Complex(3, 5)\n";
	a *= 2;
	std::cout << "a *= 2; a = " << a << "\n";
	try {
		std::cout << "a / 0 = " << a / 0 << "\n";
	}
	catch (...) {
		std::cout << "Attempt to divide by zero!";
	}

	//std::stringstream strm;
	//strm << Complex();
	//Complex z;
	//strm >> z;
	//std::cout << z;

	return 0;

}