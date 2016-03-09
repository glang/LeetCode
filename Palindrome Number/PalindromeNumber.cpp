class Solution {
public:
    static bool isPalindrome(int x) {
        if (x < 0)
        	return false;

     	int digits = 0, y = x;

     	while (y) {
     		++digits;
     		y /= 10;
     	}

     	for (int i = 0; i < digits / 2; ++i) {
     		if (x / (int) pow(10, i) % 10 != x / (int) pow(10, digits - i - 1) % 10)
                return false;

    	return true;   
    }
};