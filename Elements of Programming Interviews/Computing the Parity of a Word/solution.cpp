/*
10110 -> 10101
*/

short parity(unsigned long n) {
	short toggle = 0;

	while (n) {
		toggle ^= 1;
		n &= n - 1;
	}

	return toggle;
}