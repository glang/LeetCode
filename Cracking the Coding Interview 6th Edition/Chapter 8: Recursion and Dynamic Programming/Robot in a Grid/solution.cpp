#include <vector>
#include <iostream>

using namespace std;

//robot can only move down or right. Starts at top left corner.
//goal is to get to bottom right corner with off limit cells that can't be stepped on

/*
0 0 0 1 
0 1 0 1
0 1 0 1
0 0 0 0
*/

void traverse(int cur_r, int cur_c, vector<pair<int, int>> path, int** grid, int max_r, int max_c) {
	if (cur_r == max_r - 1 && cur_c == max_c - 1) {
		for (auto& item : path) {
			cout << item.first << " " << item.second << endl;
		}

		cout << endl;
	}

	if (cur_r != max_r - 1 && grid[cur_r + 1][cur_c] != 1) {
		vector<pair<int, int>> newPath(path);
		newPath.push_back(pair<int, int>(cur_r + 1, cur_c));
		traverse(cur_r + 1, cur_c, newPath, grid, max_r, max_c);
	}

	if (cur_c != max_r - 1 && grid[cur_r][cur_c + 1] != 1) {
		vector<pair<int, int>> newPath(path);
		newPath.push_back(pair<int, int>(cur_r, cur_c + 1));
		traverse(cur_r, cur_c + 1, newPath, grid, max_r, max_c);
	}
}

int main() {
	
}