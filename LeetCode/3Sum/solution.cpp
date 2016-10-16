class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        
        if (nums.size() < 3) return {};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int toFind = -nums[i] - nums[j];
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), toFind);
                if (*iter == toFind) {
                    res.insert({nums[i], nums[j], toFind});
                }
            }
        }
        
        return vector<vector<int>>(res.begin(), res.end());
    }
};