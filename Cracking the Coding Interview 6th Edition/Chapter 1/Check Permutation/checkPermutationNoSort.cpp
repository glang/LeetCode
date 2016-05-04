#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool checkPermutation(string first, string second) {
	if (first.size() != second.size()) {
		return false;
	}

	unordered_map<char, int> charFreq;

	for (char& c : first) {
		++charFreq[c];
	}

	for (char& d : second) {
		--charFreq[d];

		if (charFreq[d] < 0) {
			return false;			
		}
	}

	return true;
}

int main() {}