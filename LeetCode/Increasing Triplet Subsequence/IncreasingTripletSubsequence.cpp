class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums.at(i);
            if (cur <= n1)
            	n1 = cur;
            else if (cur <= n2)
            	n2 = cur;
            else
            	return true;
        }
        
        return false;
    }
};

// [1, -2, 3, -2, 5]
// [2, 4, -2, -3]
// [4, 5, 1, 0, 2, 3]
// [2, 5, 1, -5, 6]
// 4, -2, 7, -3, 9 