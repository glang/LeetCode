#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

/* Multiply A and B

idea 1: just add A to itself B times

2*5 == 2+2+2+2+2 || 5+5

idea 2: bit shift A by the log2(B) then add A*(B - B^(log2(B)))

11*13

*/

pair<int, int> log2(int in) {
	int log = 0;

	while (1 << log < in) {
		++log;
	}

	return pair<int, int>({log, (1 << log) - in});
}

int multiply(int A, int B) {
	int max = std::max(A, B);
	int min = std::min(A, B);
	pair<int, int> logDiff = log2(min);

	cout << logDiff.first << " " << logDiff.second << endl;

	int result = max << logDiff.first;

	for (int i = 0; i < logDiff.second; ++i) {
		result -= max;
	}

	return result;
}

int main() {
	cout << multiply(11, 13) << endl;
}