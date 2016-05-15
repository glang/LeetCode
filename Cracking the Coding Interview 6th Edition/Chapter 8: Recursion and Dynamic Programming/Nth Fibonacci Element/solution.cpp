#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

int memoFib(int n, vector<int>& cache) {
	if (n == 0 || n == 1) {
		return n;
	}

	if (cache.at(n) != -1) {
		return cache.at(n);
	}
	
	cache[n] = memoFib(n - 1, cache) + memoFib(n - 2, cache);
	return cache.at(n);
}

int main() {
	int n = 3;

	cout << fib(n) << endl;

	vector<int> cache(n + 1, -1);
	cout << memoFib(n, cache) << endl;

	return 0;
}