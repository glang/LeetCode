class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        
        for (int i = 0; i != s.size(); ++i) {
            int cur = 0;
            set<char> list;
            for (int j = i; j != s.size(); ++j) {
                if (list.count(s.at(j)))
                    break;
                list.emplace(s.at(j));
                cur++;
            }

            if (cur > max)
                max = cur;
        }

        return max;
    }
};