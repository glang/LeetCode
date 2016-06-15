void cap(string& A) {
	bool prevIsSpace = true;

	for (int i = 0; i < A.size(); ++i) {
		if (prevIsSpace && A[i] >= 'a' && A[i] <= 'z') {
			A[i] = toupper(A[i]);
		}

		prevIsSpace = A[i] == ' ';
	}
}