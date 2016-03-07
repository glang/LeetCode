#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static string convert(string s, int numRows) {
    	vector<vector<char>> vecs(numRows);
        int cycleLen = numRows * 2 - 2;
        string ret = "";

        for (int i = 0; i < s.size(); ++i) {
        	int spot = i % cycleLen;
        	cout << "spot: " << spot << endl;
        	if (spot < numRows)
        		vecs.at(spot).push_back(s.at(i));
        	else
        		vecs.at(numRows - spot % numRows - 1).push_back(s.at(i));
        }

        for (auto &x : vecs)
        	for (auto &y : x)
        		ret += y;

        return ret;
    }
};

int main() {
	cout << Solution::convert("PAYPALISHIRING", 4) << endl;
}

/*

a     g
b   f h
c e   i
d

*/