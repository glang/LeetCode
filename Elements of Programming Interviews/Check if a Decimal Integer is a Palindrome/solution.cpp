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
	int msb_spot = numDigits;

	return true;
}

int main() {
	isPalindrome(121);
	return 0;
}