array<array<Pixel, SIZE> rotateMatrix(array<array<Pixel, SIZE>, SIZE> A) {
	array<array<Pixel, SIZE>> B;

	for (int r = 0; r < SIZE; ++r) {
		for (int c = 0; c < SIZE; ++c) {
			B[r][c] = A[SIZE - 1 - r][c];
		}
	}

	return B;
}

/*
1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3

 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16
*/