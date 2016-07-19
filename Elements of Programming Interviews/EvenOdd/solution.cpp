#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void EvenOdd(vector<int> &A) {
	int start = 0, end = A.size() - 1;

	while (start < end) {
		if (A[start] % 2 == 1 && A[end] % 2 == 0) {
			swap(A[start], A[end]);
			++start;
			--end;
		} else {
			if (A[start] % 2 == 0) {
				++start;
			}
			if (A[end] % 2 == 1) {
				--end;
			}
		}
	}
}

int main() {
	vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	EvenOdd(A);

	for (auto const x : A) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}