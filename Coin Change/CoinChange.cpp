class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min(amount + 1, -1);
   		min.at(0) = 0;

   		for (int i = 1; i <= amount; ++i) {
   			for (int j = 0; j < coins.size(); ++j) {
   				int oldVal = min[i - coins[j]];
   				if (i >= coins[j] && oldVal != -1 && (min[i] == -1 || oldVal + 1 < min[i]))
   					min[i] = oldVal + 1;
   			}
   		}

   		if (min[amount] == -1)
   			return -1;
   		return min[amount];
    }
};

/*

coins = {2, 5, 10, 25}

S = 7

      [0,  1, 2,  3,  4,  5,  6,  7]
min = [0, -1, 1, -1, -1, -1, -1, -1]

*/