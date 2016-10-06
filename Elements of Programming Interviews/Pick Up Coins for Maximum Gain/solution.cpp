/*


0 1 2 3 4 5 6
3 1 4 5 9 2 6

maxGain(s, e)
  max(coins[s] + accumulate(coins.begin() + s + 1, coin.begin() + e) - maxGain(s + 1, e)), coins[e] + accumulate(coins.begin() + s, coins.begin() + e - 1) - maxGain(s, e - 1);
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxGain(vector<int>& coins, int s, int e, vector<vector<int>>& memo, int sum);

int maxGainRes(vector<int>& coins) {
	vector<vector<int>> memo(coins.size(), vector<int>(coins.size(), -1));
	int sum = accumulate(coins.begin(), coins.end(), 0);
	return maxGain(coins, 0, coins.size() - 1, memo, sum);
}

int maxGain(vector<int>& coins, int s, int e, vector<vector<int>>& memo, int sum) {
	if (s == e) {
		return coins[s];
	}

	if (memo[s][e] == -1) {
		int first = sum - maxGain(coins, s + 1, e, memo, sum - coins[s]);
		int sec = sum - maxGain(coins, s, e - 1, memo, sum - coins[e]);
		memo[s][e] = max(first, sec);
	}

	return memo[s][e];
}

int main() {
	vector<int> coins{10, 25, 5, 1, 10, 5};

	cout << maxGainRes(coins) << endl;

	return 0;
}
