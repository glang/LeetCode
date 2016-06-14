
/*

3 1 4 1 5 9 2

3 1 1 2 5 9 4

*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void partition(vector<int> &A, int idx) {
	int pivot = A[idx];

	int smaller = 0, bigger = A.size() - 1;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] < pivot) {
			swap(A[i], A[smaller++]);
		}
	}

	for (int i = A.size() - 1; i >= 0; --i) {
		if (A[i] > pivot) {
			swap(A[i], A[bigger--]);
		}
	} 
}

int main() {
	vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

	partition(A, 2);

	for (const auto &x : A) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}