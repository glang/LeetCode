#include <vector>
#include <iostream>

using namespace std;

int scoreCombos(vector<int> values, int goal) {
	vector<vector<int>> grid(values.size(), vector<int>(goal + 1, 0));
	grid[0][0] = 1;

	for (int i = 0; i < values.size(); ++i) {
		for (int j = 0; j < goal + 1; ++j) {
			grid[i][j] += i == 0 ? 0 : grid[i - 1][j];
			grid[i][j] += j - values[i] < 0 ? 0 : grid[i][j - values[i]];
		}
	}

	return grid.back().back();
}

int main() {
	cout << scoreCombos({2, 3, 7}, 12) << endl;

	return 0;
}