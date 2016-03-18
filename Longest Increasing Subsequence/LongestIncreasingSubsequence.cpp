class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
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
2,3,7,28,101
2,3,7,28,101,102
2,3,7,28,101,102, 103
*/