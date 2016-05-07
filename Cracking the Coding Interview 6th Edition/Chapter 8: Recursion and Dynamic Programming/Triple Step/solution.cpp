#include <vector>
#include <iostream>

using namespace std;

//A child can take 1, 2, or 3 steps, how many ways can the child climb n steps?

int tripleStep(int n) {
	if (n == 0) {
		return 1;
	} else if (n < 0) {
		return 0;
	}

	return tripleStep(n - 1) + tripleStep(n - 2) + tripleStep(n - 3);
}

int tripleStepMemo(int n, vector<int>& cache) {
	int ret = 0;

	if (n == 0) {
		return 1;
	} else if (n < 0) {
		return 0;
	}

	if (cache[n] != -1) {
		return cache[n];
	} else {
		cache[n] = tripleStepMemo(n - 1, cache) + tripleStepMemo(n - 2, cache) + tripleStepMemo(n - 3, cache);
		return cache[n];
	}
}

int main() {

	int totalSteps = 10;
	vector<int> cache(totalSteps + 1, -1);

	cout << tripleStep(totalSteps) << endl;
	cout << tripleStepMemo(totalSteps, cache) << endl;
}