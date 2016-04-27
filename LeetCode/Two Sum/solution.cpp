class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums.at(i);

            auto it = myMap.find(key);
            
            if (it != myMap.end())
                return vector<int>{myMap.at(key), i};
            
            myMap.emplace(nums.at(i), i);
        }
    }
};