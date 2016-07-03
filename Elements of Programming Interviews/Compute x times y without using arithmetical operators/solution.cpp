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
	unsigned tempa = a, tempb = b, k = 1, carry = 0, result = 0;

	while (tempa || tempb || carry) {
		unsigned ak = a & k, bk = b & k;
		result |= (ak ^ bk ^ carry);
		carry = (ak & bk) | (carry & (ak | bk));
		tempa >>= 1;
		tempb >>= 1;
		k <<= 1;
		carry <<= 1;
	}

	return result;
}

int main() {
	cout << add(3U, 3U) << endl;
	cout << mult(3U, 3U) << endl;
	return 0;
}