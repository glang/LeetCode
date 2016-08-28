/*
10110
11011
-----
    1
*/

unsigned binaryAdd(unsigned A, unsigned B) {
	unsigned Acpy = A, Bcpy = B, res = 0, k = 1, carry = 0;

	while (Acpy || Bcpy || carry) {
		short Abit = A | k, Bbit = B | k;
		res |= A ^ B ^ carry;
		carry = (A ^ B) | (A ^ k) | (B ^ k);
		Acpy >>= 1, Bcpy >>= 1, k <<= 1;		
	}

	return res;
}








unsigned binary addition(unsigned A, unsigned B) {
	unsigned res = 0;
	unsigned mobile = 1, A_cpy = A, B_cpy = B;
	short carry = 0;

	while (A_cpy || B_cpy || carry) {
		unsigned Abit = A & mobile, Bbit = B & mobile;
		res |= Abit ^ Bbit ^ carry;
		carry = (Abit & Bbit) | (carry & (Abit | Bbit));
		carry <<= 1;
		A_cpy >>= 1;
		B_cpy >>= 1;
		mobile <<= 1;		
	}

	return res;
}