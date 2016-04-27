#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LNS(vector<int> &A) {
	vector<int> dp(A.size(), 1);

	for (int i = 1; i < A.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[i] >= A[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;			
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main() {
	vector<int> input{3,1,4,1,5,9,2,6,1,1,1,1};

	cout << LNS(input) << endl;

	return 0;
}

/*
1 1 2 2 3 4 3 4 3 4 5 6
3 1 4 1 5 9 2 6 1 1 1 1

3
--- 1
1
--- 4
1
1 4
--- 1
1
1 1
--- 5
1
1 1
1 1 5
--- 9
1
1 1
1 1 5
1 1 5 9
--- 2
1
1 1
1 1 2
1 1 5 9
--- 6
1
1 1
1 1 2
1 1 5 6
--- 1
1
1 1
1 1 1
1 1 5 6
--- 1
1
1 1
1 1 1
1 1 1 1
1 1 5 6



6 3 1 6 3 9 3 7 7 1 1 1 1 1

6
---
3
---
1
---
1
1 6
---
1
1 3
---
1
1 3
1 3 9
---
1
1 3
1 3 3
---
1
1 3 
1 3 3
1 3 3 7
---
1
1 3 
1 3 3
1 3 3 7 7
---
*/