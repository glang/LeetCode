class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.empty()) return 0;
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	int min = nums.at(i), firstNum = min, firstLength = 1, secNum = min, secLength = 1;
        	for (int j = i; j < nums.size(); ++j) {
        		int curNum = nums.at(j);
        		if (curNum > firstNum) {
        			firstNum = curNum;
        			++firstLength;
        		}
        		else {
        			if (curNum > min && secLength == 1) {
        				++secLength;
        				secNum = curNum;
        			} 
        			else if (curNum > secNum) {
        				++secLength;
        				secNum = curNum;
        			}
	        		if (secLength > firstLength) {
	        			firstLength = secLength;
	        			firstNum = secNum;
	        			secLength = 1;
	        			secNum = min;
	        		}
        		}
        	}

        	max = std::max(max, firstLength);
        }

        return max;
    }
};

// [2,5,6,3,4,5]
// [10,9,2,5,3,7,200,18,101,102,103]