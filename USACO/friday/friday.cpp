/*
ID: granger1
PROG: friday
LANG: C++11
*/

#include <fstream>
#include <iostream>
#define DAYS_PER_WEEK 7
#define MONTHS 12

using namespace std;

int main() {
	ifstream in("friday.in");
	ofstream out("friday.out");

	int years, tally[DAYS_PER_WEEK] = {0};
	int months[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	in >> years;
	int day = 0;

	for (int i = 1900; i != 1900 + years; ++i) {
		if (i == 2000 || (i % 100 != 0 && i % 4 == 0))
			months[1] = 29;
		else
			months[1] = 28;

		for (int j = 0; j != MONTHS; ++j) {
			++tally[(day + 13 - 1) % 7];
			day += months[j];
		}
	}

	out << tally[5] << " " << tally[6] << " ";

	for (int i = 0; i != 5; i++) {
		out << tally[i];

		if (i < 4)
			out << " ";
		else
			out << endl;
	}

	return 0;
}