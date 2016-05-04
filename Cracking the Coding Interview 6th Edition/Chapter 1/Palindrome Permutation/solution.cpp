#include <locale>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool PalindromePermutation(string input) {
	unordered_map<char, int> frequency;

	for (char& c : input) {
		if (isLetter(c)) {
			c = tolower(c);
			++frequency[c];
		}
	}


	bool oddFound = false;
	for (auto& item : frequency) {
		if (item.second % 2 == 1) {
			if (oddFound) {
				return false;
			} else {
				oddFound = true;
			}
		}
	}

	return true;
}

int main() {
	string test = "aba";
	string test2 = "aaabb";
	string test3 = "abcdba";

	cout << PalindromePermutation(test) << endl;
	cout << PalindromePermutation(test2) << endl;
	cout << PalindromePermutation(test3) << endl;
}