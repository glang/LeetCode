/*
0     0      9*0        0
9     9      9*1        9
99    90    90*2      189 
999   900  900*3     2889
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

        unsigned long long numberDifference = ceil((n - totalDigits) / currentDigits);
        num += numberDifference;
        totalDigits += numberDifference * currentDigits;

        if ((n - totalDigits) % currentDigits != 0) {
            ++num;
            totalDigits += currentDigits;
        }
        
        return to_string(num)[currentDigits - (totalDigits - n) - 1] - '0';
    }
};
