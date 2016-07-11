#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(int num) {
	if (num < 0) {
		return false;
	}

	if (num == 0) {
		return true;
	}

	int numDigits = floor(log10(num)) + 1;
	int msb_mask = pow(10, numDigits - 1);

	for (int i = 0; i < numDigits/2; ++i) {
		if (num / msb_mask != num % 10) {
			return false;
		}

		num %= msb_mask;
		num /= 10;
		msb_spot /= 100;
	}

	return true;
}

int main() {
	cout << isPalindrome(121) << endl;
	return 0;
}