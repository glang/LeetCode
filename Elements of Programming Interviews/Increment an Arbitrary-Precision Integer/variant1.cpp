#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string addBitStrings(const string &A, const string &B) {
	string res;
	bool carry = false;
	int longest = max(A.size(), B.size());

	for (int i = 0; i < longest; ++i) {
		bool A1 = i < A.size() ? (A[i] == '1') : false;
		bool B1 = i < B.size() ? (B[i] == '1') : false;
		if (carry) {
			if (A1 && B1) {
				res.push_back('1');
			} else if (!A1 && !B1){
				carry = false;
				res.push_back('1');
			} else {
				res.push_back('0');
			}
		} else {
			if (A1 && B1) {
				carry = true;
				res.push_back('0');
			} else if (!A1 && !B1){
				res.push_back('1');
			} else {
				carry = true;
				res.push_back('0');
			}
		}
	}

	if (carry) {
		res.push_back('1');
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {
	string A{"111"};
	string B{"1"};

	cout << addBitStrings(A, B) << endl;
}