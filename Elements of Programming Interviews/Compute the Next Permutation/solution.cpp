/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

4 3 2 1

3 5 7 4 3 2
3 7 5 4 3 2 -> 3 7 2 3 4 5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextPerm(vector<int> A) {
	int toSwapIdx = -1;
	vector<int> result;

	for (int i = A.size() - 1; i > 0; --i) {
		if (A[i - 1] < A[i]) {
			toSwapIdx = i - 1;
			break;
		}
	}

	if (toSwapIdx == -1) {
		return result;
	}

	result = vector<int>(A);
	int biggerIdx = toSwapIdx + 1;
	for (int i = toSwapIdx + 1; i < A.size(); ++i) {
		if (A[i] > A[toSwapIdx] && A[i] < A[biggerIdx]) {
			biggerIdx = i;
		}
	}

	swap(result[toSwapIdx], result[biggerIdx]);
	sort(result.begin() + toSwapIdx + 1, result.end());

	return result;
}

int main() {
	vector<int> test{1, 2, 3, 4};

	while (!test.empty()) {
		test = nextPerm(test);
		for (int x : test) {
			cout << x << " ";
		}
		cout << endl;
	}
}