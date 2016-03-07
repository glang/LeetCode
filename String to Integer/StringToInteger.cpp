class Solution {
public:
    int myAtoi(string str) {
    	auto firstNonWS = str.find_first_not_of(' ');

    	if (firstNonWS == -1) return 0;

    	string ret = str.substr(firstNonWS, str.size() - firstNonWS);
     
		for (int i = 0; i < ret.size(); ++i) {
			char c = ret.at(i);

			if (i == 0 && (c == '-' || c == '+') && ret.size() > 1) continue;
			if (c < '0' || c > '9') return 0;
		}
  
		if (ret == "") return 0;

		if (ret.at(0) == '-' && (ret.size() > 20 || ret.compare("-9223372036854775807") > 1)) return INT_MIN;
		else if (ret.at(0) == '+' && (ret.size() > 20 || ret.compare("+9223372036854775807") > 1)) return INT_MAX;
		else if (ret.size() > 19 || ret.compare("9223372036854775807") > 1) return INT_MAX;
		
		long long l = stoll(ret);

		if (l < INT_MIN) return INT_MIN;
		if (l > INT_MAX) return INT_MAX;

		return stoi(ret);
    }
};