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

	if (n - 1 >= 0) {
		if (cache[n - 1] == -1) {
			cache[n - 1] = tripleStepMemo(n - 1, cache);
		}

		ret += cache[n - 1];
	}

	if (n - 2 >= 0) {
		if (cache[n - 2] == -1) {
			cache[n - 2] = tripleStepMemo(n - 2, cache);
		}
		
		ret += cache[n - 2];
	}

	if (n - 3 >= 0) {
		if (cache[n - 3] == -1) {
			cache[n - 3] = tripleStepMemo(n - 3, cache);
		}
		
		ret += cache[n - 3];
	}

	return ret;
}

int main() {

	int totalSteps = 10;
	vector<int> cache(totalSteps + 1, -1);

	cout << tripleStep(totalSteps) << endl;
	cout << tripleStepMemo(totalSteps, cache) << endl;
}