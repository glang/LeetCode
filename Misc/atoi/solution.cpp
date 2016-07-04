#include <iostream>
#include <string>

using namespace std;

int atoi(string s) {
	int res = 0;
	bool isNeg = s[0] == '-';
	int start = isNeg ? 1 : 0;
	for (int i = start; i < s.size(); ++i) {
		res = res * 10 + (s[i] - '0');
	}

	return isNeg ? res * -1 : res;
}

int main() {
	cout << atoi("-123") << endl;
}