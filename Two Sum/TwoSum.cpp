class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < sorted.size() - 1 && sorted.at(i) < target; ++i) {
            if (binary_search(sorted.begin() + i + 1, sorted.end() , target - sorted.at(i))) {
                auto val1Iter = find(nums.begin(), nums.end(), sorted.at(i));
                auto val2Iter = find(nums.begin(), nums.end(), target - sorted.at(i));
                vector<int> ret{static_cast<int>(val1Iter - nums.begin()), static_cast<int>(val2Iter - nums.begin())}; 
                return ret;
            }
        }
    }

};