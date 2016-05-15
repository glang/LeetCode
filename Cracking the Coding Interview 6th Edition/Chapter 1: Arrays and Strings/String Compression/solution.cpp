#include <string>
#include <iostream>

using namespace std;

string stringCompression(string orig) {
	string newString;
	int count = 1;
	int i;
	for (i = 0; i < orig.size() - 1; ++i) {
		if (orig[i] == orig[i + 1]) {
			++count;
		} else {
			newString.push_back(orig[i]);
			newString.push_back('0' + count);
			count = 1;
		}
	}

	newString.push_back(orig[i]);
	newString.push_back('0' + count);

	return orig.size() <= newString.size() ? orig : newString;
}

int main() {
	string orig("aaaaabbb");

	cout << stringCompression(orig) << endl;
}