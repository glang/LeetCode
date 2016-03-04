class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, cur = 0;
        map<char, int> track;
        
        for (int i = 0; i != s.size(); ++i) {
        	auto iter = track.find(s.at(i));
            if (iter == track.end()) {
            	cur++;
            	track.emplace(s.at(i), i);
            } else {
            	if (cur > max)
            		max = cur;
            	int distance = i - track.at(s.at(i));
            	cur = distance <= cur ? distance : cur + 1;
            	track[s.at(i)] = i;
            }
        }

    	if (cur > max)
    		max = cur;

        return max;
    }
};