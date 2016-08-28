/*
10110
11011
-----
    1
*/

#include <iostream>

using namespace std;

unsigned binaryAdd(unsigned A, unsigned B) {
	unsigned Acpy = A, Bcpy = B, res = 0, k = 1, carry = 0;

	while (Acpy || Bcpy || carry) {
		unsigned Abit = A & k, Bbit = B & k;
		res |= Abit ^ Bbit ^ carry;
		carry = (Abit & Bbit) | (Abit & carry) | (Bbit & carry);
		Acpy >>= 1, Bcpy >>= 1, k <<= 1, carry <<= 1;		
	}

	return res;
}

int main() {
	cout << binaryAdd(3, 3) << endl;
}