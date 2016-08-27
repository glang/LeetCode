/*
0 1 2 3 4 5 6 7 8 9
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> enumPrimes(int n) {
	vector<int> primes;

	for (int i = 2; i <= n; ++i) {
		bool div = false;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				div = true;
				break;
			}
		}

		if (!div) {
			primes.push_back(i);
		}
	}

	return primes;
}

int main() {
	vector<int> primes = enumPrimes(18);

	for (const int &i : primes) {
		cout << i << " ";
	}

	cout << endl;

	return 0;
}