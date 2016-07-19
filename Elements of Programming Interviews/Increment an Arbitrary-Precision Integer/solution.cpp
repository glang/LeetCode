/*
314159
*/

void incIntArr(vector<int> &A) {
	for (int i = A.size() - 1; i >= 0; --i) {
		if (A[i] == 9) {
			A[i] = 0;
		} else {
			A[i] += 1;
			break;
		}
	}

	if (A[0] == 0) {
		A.insert(A.begin(), 1);
	}
}