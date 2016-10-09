/*

"  asdf  asd  as sdasdfs "

*/

#include <string>
#include <iostream>

using namespace std;

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void capFirstLetter(string &s) {
	bool prevIsSpace = true;

	for (char &c : s) {
		if (prevIsSpace && isLetter(c)) {
            c = toupper(c);
		}

		if (c == ' ') {
			prevIsSpace = true;
		} else {
			prevIsSpace = false;
		}
	}
}

int main() {
	string s{"  asdf  bsd  cs ddasdfs "};
	capFirstLetter(s);
	cout << s << endl;

	return 0;
}