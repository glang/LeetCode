/*
ID: granger1
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int convert(const string& input);

int main() {
	ifstream in("ride.in");
	ofstream out("ride.out");

	string ufo, group;

	in >> ufo >> group;

	int ufoNum = convert(ufo), groupNum = convert(group);

	if (ufoNum % 47 == groupNum % 47)
		out << "GO" << endl;
	else
		out << "STAY" << endl;

	return 0;
}

int convert(const string& input) {
	int total = 1;

	for (int i = 0; i != input.length(); i++) {
		total *= input.at(i) - 'A' + 1;
	}

	return total;
}