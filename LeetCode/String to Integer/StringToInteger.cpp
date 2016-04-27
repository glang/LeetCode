class Solution {
public:
    int myAtoi(string str) {
    	int firstNonWS = str.find_first_not_of(' ');
    	
    	if (firstNonWS == string::npos) return 0;
    	
    	string trim = str.substr(firstNonWS, str.size() - firstNonWS);
    	long long res = 0, sign = 1;
    	
		for (int i = 0; i < trim.size(); ++i) {
			char c = trim.at(i);

			if (i == 0 && (c == '-' || c == '+')) {
			    if (trim.size() == 1) return 0;
				if (c == '-')
					sign = -1;
				continue;	
			}

			if (c >= '0' && c <= '9') {
				res = res * 10 + c - '0';

				if (res * sign >= INT_MAX) return INT_MAX;
				if (res * sign <= INT_MIN) return INT_MIN;
			} else {
				break;
			}
		}
  
		return sign * res;
    }
};