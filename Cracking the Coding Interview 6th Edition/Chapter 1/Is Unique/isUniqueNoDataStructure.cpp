#include <string>
#include <algorithm>

using namespace std;

bool isUnique(string input) {
	sort(input.begin(), input.end());

	for (int i = 0; i < input.size() - 1; ++i) {
		if (input.at(i) == input.at(i + 1)) {
			return false;
		}
	}

	return true;
}

int main() {}