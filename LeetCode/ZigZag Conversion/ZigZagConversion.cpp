#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static string convert(string s, int numRows) {
    	vector<string> vecs(numRows);
        int cycleLen = numRows * 2 - 2;
        string ret = "";

        if (numRows == 1)
        	return s;

        for (int i = 0; i < s.size(); ++i) {
        	int spot = i % cycleLen;
        	if (spot < numRows)
        		vecs.at(spot).push_back(s.at(i));
        	else
        		vecs.at(numRows - spot % numRows - 2).push_back(s.at(i));
        }

        for (auto &x : vecs)
    		ret += x;

        return ret;
    }
};

int main() {
	cout << Solution::convert("A", 1) << endl;
}

/*

p     i     n
a   l s   i g
y a   h r
p     i

*/