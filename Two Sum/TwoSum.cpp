class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < sorted.size() - 1; ++i) {
            int toFind = target - sorted.at(i);

            if (binary_search(sorted.begin() + i + 1, sorted.end() , toFind)) {
                auto val1Iter = find(nums.begin(), nums.end(), sorted.at(i));
                decltype(val1Iter) val2Iter;
                
                if (toFind == sorted.at(i))
                    val2Iter = find(val1Iter + 1, nums.end(), toFind);
                else
                    val2Iter = find(nums.begin(), nums.end(), toFind);

                vector<int> ret{static_cast<int>(val1Iter - nums.begin()), static_cast<int>(val2Iter - nums.begin())}; 
                return ret;
            }
        }
    }
};