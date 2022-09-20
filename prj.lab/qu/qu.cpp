#include <iostream>
#include <sstream>

class Mat2x2 {
public:
	Mat2x2() :
		Mat2x2(0, 0, 0, 0)
	{};
	Mat2x2(double a, const double b, const double c, const double d)
		: i1j1(a),
		  i2j1(b),
		  i1j2(c),
		  i2j2(d)
	{};

	Mat2x2(double one): 
		i1j1(one),
		i2j1(one),
		i1j2(one),
		i2j2(one)
	{};

	~Mat2x2() = default;

	bool operator==(Mat2x2& rhs) const {
		if (i1j1 == rhs.i1j1 && i2j1 == rhs.i2j1 && i1j2 == rhs.i1j2 && i2j2 == rhs.i2j2) {
			return true;
		}
		else {
			return false;
		}
	};

	Mat2x2 operator+(Mat2x2& rhs){
		Mat2x2 temp;
		temp.i1j1 = i1j1 + rhs.i1j1;
		temp.i2j1 = i2j1 + rhs.i2j1;
		temp.i1j2 = i1j2 + rhs.i1j2;
		temp.i2j2 = i2j2 + rhs.i2j2;
		return temp;
	}
	Mat2x2 operator-(Mat2x2& rhs) {
		Mat2x2 temp;
		temp.i1j1 = i1j1 - rhs.i1j1;
		temp.i2j1 = i2j1 - rhs.i2j1;
		temp.i1j2 = i1j2 - rhs.i1j2;
		temp.i2j2 = i2j2 - rhs.i2j2;
		return temp;
	}

	//Mat2x2 operator*(Mat2x2& rhs) {
	//	Mat2x2 temp;
	//	temp.i1j1 = i1j1 * rhs.i1j1;
	//	temp.i2j1 = i2j1 * rhs.i2j1;
	//	temp.i1j2 = i1j2 * rhs.i1j2;
	//	temp.i2j2 = i2j2 * rhs.i2j2;
	//	return temp;
	//}



	double i1j1{ 0 };
	double i2j1{ 0 }; 
	double i1j2{ 0 };
	double i2j2{ 0 };
};

int main()
{
	Mat2x2 a;
	Mat2x2 b (0, 0, 0, 0);
	if (a == b) {
		std::cout << "OK!\n";
	}
	Mat2x2 c(1, 2, 3, 4);
	Mat2x2 d(1);
	Mat2x2 e;
	e = c + d;
	Mat2x2 f(2, 3, 4, 5);
	if (e == f) {
		std::cout << "OK!\n";
	}
	e = c - d;
	f = Mat2x2 (0, 1, 2, 3);
	if (e == f) {
		std::cout << "OK!\n";
	}
}


// + - * T обратная матрица, равество, неравнство, присваивание, 
