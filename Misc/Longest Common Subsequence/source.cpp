#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lcs(string s, string t, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	if (s.at(i) == t.at(j))
		return 1 + lcs(s, t, i - 1, j - 1);
	return max(lcs(s, t, i, j - 1), lcs(s, t, i - 1, j));
}

int main() {
	cout << lcs("ABAZDC", "BACBAD", 5, 5) << endl;
}