/*

a b c d
1 0 3 2

prev = d
swap[a, d]
swap[c, prev]

*/

void permute(vector<int> original, vector<int> perms) {
	vector<int> result(original.size(), 0);

	for (int i = 0; i < original.size(); ++i) {
		result[perm[i]] = original[i];
	}

	for (int j = 0; j < result.size(); ++j) {
		original[i] = result[i];
	}
}

void permute(vector<int> orig, vector<int> perms) {
	int temp = 0;
	for (int i = 0; i < orig.size(); ++i) {
		if (perms[i] >= 0) {
			temp = orig[i];
			int futurePosition = perm[i];
			while (futurePosition != i) {
				swap(temp, orig[futurePosition]);
				perms[futurePosition] -= orig.size();
				futurePosition = perms[futurePosition] = orig.size();
			}
		}
	}
}