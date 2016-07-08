#include <iostream>

using namespace std;

int reverseDigits(int d) {
	bool isNegative = d < 0;

	if (isNegative) {
		d = -d;
	}

	int result = 0;

	while (d) {
		result = result * 10 + d%10;
		d /= 10;
	}

	return isNegative ? -result : result;
}

int main() {
	cout << reverseDigits(123) << endl;
	cout << reverseDigits(-123) << endl;
}