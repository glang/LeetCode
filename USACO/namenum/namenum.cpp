/*
ID: granger1
PROG: namenum
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

string convert(string& word, string& input) {
	if (word.size() != input.size())
		return "-1";

	string converted = "";
	for (int i = 0; i < word.size(); ++i) {
		char letter = word.at(i);
		if (letter == 'Q' || letter == 'Z') {
			return "-1";
		} else if (letter < 'Q') {
			converted += (letter - 'A') / 3 + '2';
		} else {
			converted += (letter - 'Q') / 3 + '7';
		}
	}

	return converted;
}

int main() {
	ifstream in("namenum.in");
	ifstream dict("dict.txt");
	ofstream out("namenum.out");
	string serial;
	in >> serial;

	int found = 0;
	string word;
	while (dict >> word) {
		if (convert(word, serial) == serial) {
			found = 1;
			out << word << endl;
		}
	}

	if (found == 0) {
		out << "NONE" << endl;
	}

	return 0; 
}