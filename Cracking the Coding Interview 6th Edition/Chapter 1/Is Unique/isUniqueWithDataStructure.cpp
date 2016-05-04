#include <string>
#include <bitset>

using namespace std;

bool isUnique(string input) {
	bitset<256> all_chars;

	for (int i = 0; i < input.size(); ++i) {
		if (all_chars.test(input.at(i))) {
			return false;
		} else {
			all_chars.set(input.at(i));
		}
	}

	return true;
}

int main() {}