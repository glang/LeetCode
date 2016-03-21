class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min(amount + 1, numeric_limits<int>::max());
   		min.at(0) = 0;

   		for (int i = 1; i <= amount; ++i) {
   			for (int j = 0; j < coins.size(); ++j) {
   				if (i >= coins.at(j) && min.at(i - coins.at(j)) + 1 < min.at(i))
   					min.at(i) = min.at(i - coins.at(j)) + 1;
   			}
   		}

   		return min.at(amount);
    }
};
