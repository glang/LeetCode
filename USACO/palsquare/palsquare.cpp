/*
ID: granger1
PROG: palsquare
LANG: C++11
*/

#include <fstream>
#include <cmath>

using namespace std;

string convertBase(int num, int base) {
	string ret = "";
	int left = num;
	int radix;

	for (int i = 1; i < 30; ++i) {
		if (num < pow(base, i)) {
			radix = i - 1;
			break;
		}
	}

	for (int j = radix; j >= 0; --j) {
		int value = left / pow(base, j);
		left -= value * pow(base, j);

		if (value > 9)
			ret += 'A' + value - 10;
		else 
			ret += '0' + value;
	}

	return ret;
}

bool isPal(string& mystring) {
	for (int i = 0; i < mystring.size() / 2; ++i)
		if (mystring.at(i) != mystring.at(mystring.size() - i - 1))
			return false;

	return true;
}

int main() {
	ifstream in("palsquare.in");
	ofstream out("palsquare.out");

	int base;
	in >> base;

	for (int i = 1; i <= 300; ++i) {
		string newBase = convertBase(i * i, base);

		if (isPal(newBase)) {
			out << convertBase(i, base) << " " << newBase << endl;
		}
	}


	return 0;
}