#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseWords(string &s) {
	reverse(s.begin(), s.end());

	int start = 0, end = 0;
	while ((end = s.find(" ", start)) != string::npos) {
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}

	reverse(s.begin() + start, s.end());
}

int main() {
	string test{"test1 test2 test3"};
	reverseWords(test);
	cout << test << endl;
	return 0;
}