class Solution {
public:
	bool isPal(string &s) {
		for (int i = 0; i != s.size()/2; ++i) {
			if (s.at(i) != s.at(s.size() - i - 1))
				return false;
		}

		return true;
	}

    string longestPalindrome(string s) {
    	string longest = "";
    	int len = 0;

        for (int i = 0; i != s.size(); ++i) {
        	for (int j = s.size() - i; j >= 0; --j) {
        		string sub = s.substr(i, j);

        		if (isPal(sub) && j > len) {
        			longest = sub;
        			len = j;
        			break;
        		}
        	}
        }

        return longest;
    }
};