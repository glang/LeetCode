#include <algorithm>
#include <iostream>

using namespace std;

int my_stoi(string A) {
	bool neg = A[0] == '-';
	int res = 0;

	for (int i = neg ? 1 : 0; i < A.size(); ++i) {
		res *= 10;
		res += A[i] - '0';
	}

	return neg ? -res : res;
}

string my_itoa(int A) {
	string res;
	bool neg = A < 0;

	if (neg) {
		A = -A;
	}

	if (A == 0) {
		return "0";
	}

	while (A) {
		res += '0' + (A % 10);
		A /= 10;
	}

	if (neg) {
		res += '-';
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {
	cout << my_stoi("-123") << endl;
	cout << my_itoa(-123) << endl;
}