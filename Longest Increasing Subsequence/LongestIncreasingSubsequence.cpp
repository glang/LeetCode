class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.empty()) return 0;
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	int curNum = nums.at(i), curLength = 1;
        	for (int j = i; j < nums.size(); ++j) {
        		if (nums.at(j) > curNum) {
        			curNum = nums.at(j);
        			++curLength;
        		}
        	}

        	max = std::max(max, curLength);
        }

        return max;
    }
};

// [10,9,2,5,3,4]