class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < sorted.size() - 1; ++i) {
            int key = target - sorted.at(i);
            
            if (binary_search(sorted.begin() + i + 1, sorted.end(), key)) {
                auto val1Iter = find(nums.begin(), nums.end(), sorted.at(i));
                decltype(val1Iter) val2beg = (key == sorted.at(i)) ? val1Iter + 1 : nums.begin();
                auto val2Iter = find(val2beg, nums.end(), key);
                return vector<int>{val1Iter - nums.begin(), val2Iter - nums.begin()};
            }
        }
    }
};