/*
-5 0 2 5 6 7 10 15
 0 1 2 3 4 5  6  7
*/

int searchForIndexEle(vector<int> A) {
	int low = 0, high = A.size() - 1, i = 0;

	while (low < high) {
		i = low + (high - low) / 2;
		if (A[i] == i) {
			return i;
		} else if(A[i] > i) {
			high = i - 1;
		} else {
			low = i + 1;
		}
	}

	return -1;
}