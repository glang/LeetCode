/*
ID: granger1
PROG: beads
LANG: C++11
*/

#include <fstream>

using namespace std;

int main() {
	int N, longest = 0;
	string beads;
	ifstream in("beads.in");
	ofstream out("beads.out");

	in >> N;
	in >> beads;

	beads += beads;
	char prevColor1, prevColor2;
	int length1, length2;

	for (int j = 0; j != N; ++j) {
		length1 = 1;
		length2 = 1;
		prevColor1 = beads.at(j);
		prevColor2 = beads.at(j + N - 1);

		for (int i = j + 1; i != j + N; ++i) {
			char curChar = beads.at(i);
			char prevChar = beads.at(i - 1);
			if (curChar == 'w' || prevColor1 == 'w' || curChar == prevChar || curChar == prevColor1) {
				++length1;

				if (prevColor1 == 'w')
					prevColor1 = curChar;
			}
			else {
				break;
			}
		}

		for (int i = j + N - 2; i != j - 1; --i) {
			char curChar = beads.at(i);
			char prevChar = beads.at(i + 1);
			if (curChar == 'w' || prevColor2 == 'w' || curChar == prevChar || curChar == prevColor2) {
				++length2;

				if (prevColor2 == 'w')
					prevColor2 = curChar;
			}
			else {
				break;
			}
		}

		if (length1 + length2 > longest) {
			longest = length1 + length2;
		}
	}

	if (longest > N)
		longest = N;

	out << longest << endl;

	return 0;
}