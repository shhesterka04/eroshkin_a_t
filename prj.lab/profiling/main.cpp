#include <chrono>
#include <fstream>
#include <profiling/profiling.h>
#include <iostream>
#include <matplot/matplot.h>

int main() {
	using namespace matplot;
	std::vector<double> x = { 1,2,3,4 };
	plot(x);
	save("barchart.jpg");
	return 0;
}
