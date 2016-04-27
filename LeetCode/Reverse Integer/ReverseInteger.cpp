class Solution {
public:
    int reverse(int x) {
    	string s = to_string(x);
    	std::reverse(s.begin(), s.end());

        if (x >= 0) {
        	if (stol(s) > INT_MAX)
        		return 0;
        	return stoi(s);
        } else {
        	if (stol('-' + s.substr(0, s.size() - 1)) < INT_MIN)
        		return 0;
        	return stoi('-' + s.substr(0, s.size() - 1));
        }
    }
};