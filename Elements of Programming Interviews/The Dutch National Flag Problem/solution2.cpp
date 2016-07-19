/*
3 7 2 8 9 1 2 10
*/

void partition(vector<int> V, int pivotIdx) {
	int small = 0, big = V.size() - 1, p = V[pivotIdx];

	for (int i = 0; i < V.size(); ++i) {
		if (V[i] < p) {
			swap(V[i], V[small]);
			++small;
		}
	}

	for (int i = V.size() - 1; i >= 0 && V[i] >= p; --i) {
		if (V[i] < p) {
			swap(V[i], V[large]);
			--large;
		}
	}
}

/*
3 7 2 8 9 1 2 10

3 10 1 10 
*/

void partition(vector<int> &A, int pivotIdx) {
	int p = A[pivotIdx];
	int smaller = 0, equal = 0, larger = A.size() - 1;

	while (equal <= larger) {
		if (A[equal] == p) {
			++equal;
		} else if (A[equal] < p) {
			swap(A[equal++], A[smaller++]);
		} else {
			swap(A[equal], A[larger--])
		}
	}
}