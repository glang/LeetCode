/*

items 0 1 2 3 4 5 6
weight 10

0 -- 6 [10]
  1 -- 6 [9]
    2 -- 6 [8]
    2 -- 6 [9]
  1 -- 6 [10]
    2 -- 6 [9]
    2 -- 6 [10]

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct item;
int maxSetVal(vector<item>& items, int s, int weight, vector<vector<int>>& grid);

struct item {
	int weight;
	int value;
};

int maxSetValMain(vector<item>& items, int weight) {
	vector<vector<int>> grid(items.size(), vector<int>(weight + 1, -1));
	return maxSetVal(items, 0, weight, grid);
}

int maxSetVal(vector<item>& items, int s, int weight, vector<vector<int>>& grid) {
	if (weight <= 0 || s == items.size())
		return 0;

	if (grid[s][weight] == -1) {
	   grid[s][weight] = max(items[s].value + 
	    maxSetVal(items, s + 1, weight - items[s].weight, grid), 
	     maxSetVal(items, s + 1, weight, grid));
	}

	return grid[s][weight];
}

int main() {
  vector<item> items = {{20, 65},  {8, 35},   {60, 245}, {55, 195},
                        {40, 65},  {70, 150}, {85, 275}, {25, 155},
                        {30, 120}, {65, 320}, {75, 75},  {10, 40},
                        {95, 200}, {50, 100}, {40, 220}, {10, 99}};

  cout << maxSetValMain(items, 130) << endl;	

  return 0;
}