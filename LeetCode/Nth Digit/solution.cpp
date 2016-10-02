/*
0     0      9*0
9     9      9*1
99    90    90*2
999   900  900*3
*/

class Solution {
public:
    int findNthDigit(int n) {
        unsigned long long num = 0, totalDigits = 0, currentDigits = 1, counter = 9;
        
        while (totalDigits + counter * currentDigits < n) {
            num += counter;
            totalDigits += counter * currentDigits;
            ++currentDigits;
            counter *= 10;
        }
        
        num = max(1ull, num);
        for (totalDigits = max(1ull, totalDigits); totalDigits < n; totalDigits+=currentDigits) {
            ++num;
        }
        
        return to_string(num)[currentDigits - (totalDigits - n) - 1] - '0';
    }
};