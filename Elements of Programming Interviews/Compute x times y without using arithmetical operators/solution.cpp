/*

<< >> & | ^ ~ = ==

3: 011
2: 010
6: 110

3: 0011
3: 0011

*/

#include <iostream>

using namespace std;

unsigned add(unsigned a, unsigned b);
unsigned mult(unsigned a, unsigned b);

unsigned mult(unsigned a, unsigned b) {
	unsigned result = 0;

	while (a) {
		if (a & 1) {
			result = add(result, b);
		}

		a >>= 1;
		b <<= 1;
	}

	return result;
}

unsigned add(unsigned a, unsigned b) {
	unsigned short carry = 0;
	int count = 0;
	unsigned result = 0;

	while (a || b || carry) {
		short abit = a & 1;
		short bbit = b & 1;

		result |= ((abit ^ bbit ^ carry) << count);

		carry = (abit && bbit) || (carry && (abit || bbit));
		a >>= 1;
		b >>= 1;
		++count;
		cout << "adding" << endl;
	}

	return result;
}

int main() {
	cout << mult(3U, 3U) << endl;
	return 0;
}