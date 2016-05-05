#include <string>
#include <iostream>

using namespace std;

void URLify(string& input, int trueLength) {
	int back = input.size() - 1;

	for (int i = trueLength - 1; i >= 0; --i) {
		char& cur = input.at(i);

		if (cur == ' ') {
			input.at(back--) = '0';
			input.at(back--) = '2';
			input.at(back--) = '%';
		} else {
			input.at(back--) = cur;
		}
	}
}

int main() {
	string test = "abc d  ";
	URLify(test, 5);
	cout << test << endl;
}