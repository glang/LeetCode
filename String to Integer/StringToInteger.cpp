class Solution {
public:
	void isValid(string &str) {
		for (int i = 0; i < str.size(); ++i) {
			char c = str.at(i);

			if (i == 1 && str.size() > 1 && (c == '-' || c == '+'))
				continue;

			if (!(c >= 'a' && i <= 'z') || (c >= 'A' && c <= 'Z'))) {
				return false;	
		}

		return true;
	}

    int myAtoi(string str) {
    	auto firstNonWS = str.find_first_not_of(' ');
    	ret = str.substr(firstNonWS, str.size() - firstNonWS);
        
    	if (!isValid(ret))
    		return 0;
    	

    }
};

//overflow
//negatives
//0s
//invalid strings? spaces, other symbols, etc