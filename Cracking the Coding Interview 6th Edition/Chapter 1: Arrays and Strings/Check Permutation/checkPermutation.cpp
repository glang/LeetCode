#include <string>
#include <algorithm>

using namespace std;

bool checkPermutation(string first, string second) {
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	return first == second;
}

int main() {}