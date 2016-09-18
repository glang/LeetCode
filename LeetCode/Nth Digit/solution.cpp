class Solution {
public:
    int findNthDigit(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            int length = log10(i) + 1;
        
            if (n > count + length) {
                count += length;
            } else {
                /*
                get 2nd digit
                size == 7
                div by 10 ^ size - diff
                mod by 10
                4738765
                */
                int diff = n - count;
                return i / (int) pow(10, length - diff) % 10;
            }
        }
        
        return 0;
    }
};