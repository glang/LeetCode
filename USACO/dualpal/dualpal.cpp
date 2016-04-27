/*
ID: granger1
PROG: dualpal
LANG: C++11
*/

#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

string convertBase(int num, int newBase) {
	string ret;
	int basepower = newBase;
	int position = 0;

	while (num > basepower) {
		position++;
		basepower *= newBase;
	}

	int leftover = num;
	for (int i = position; i >= 0; --i) {
		int digit = leftover / pow(newBase, i);
		leftover -= digit * pow(newBase, i);

		if (digit > 9)
			ret += 'A' + digit - 10;
		else
			ret += '0' + digit;
	}

	return ret;
}

bool isPal(string myString) {
	string copy = myString;
	reverse(copy.begin(), copy.end());
	return myString == copy;
}

int main() {
	ifstream in("dualpal.in");
	ofstream out("dualpal.out");

	int N, S, found = 0;
	in >> N >> S;

	S++;
	for(;found < N; ++S) {
		int numPals = 0;
		for (int i = 2; numPals < 2 && i <= 10; ++i) {
			if (isPal(convertBase(S, i))) {
				++numPals;
			}
		}

		if (numPals == 2) {
			++found;
			out << S << endl;
		}
	}

	return 0;
}