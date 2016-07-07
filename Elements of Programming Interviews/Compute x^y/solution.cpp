/*
x^6
(x^2) ^ 3
*/

#include <iostream>

using namespace std;

double exp(double x, int y) {
	if (y == 0) {
		return 1;
	}

	if (y & 1) {
		return x * exp(x, y - 1);
	} else {
		return exp(x * x, y >> 1);
	}
}

int main() {
	cout << exp(2, 7) << endl;
	return 0;
}