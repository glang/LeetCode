class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        	return false;

     	int digits = 0, y = x;

     	while (y) {
     		++digits;
     		y /= 10;
     	}

     	for (int i = 0; i < digits / 2; ++i) {
     		
     	}

    	return true;   
    }
};

/*
666
569
1001

101
50.5

22
11
5.5
2.25

*/