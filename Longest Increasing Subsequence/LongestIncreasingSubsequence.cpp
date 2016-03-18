class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ends;

        for (int i = 0; i < nums.size(); ++i) {
            auto iter = std::lower_bound(ends.begin(), ends.end(), nums.at(i));
            if (iter == ends.end()) ends.push_back(nums.at(i));
            else *iter = nums.at(i);
        }

        return ends.size();
    }
};

// [10,9,2,5,3,7,200,18,101,102,103]

/*
10
9
2
2,5
2,3
2,3,7
2,3,7,200
2,3,7,18
2,3,7,18,101
2,3,7,18,101,102
2,3,7,18,101,102, 103
*/