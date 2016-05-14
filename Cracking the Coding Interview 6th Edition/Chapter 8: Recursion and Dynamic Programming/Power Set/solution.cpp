#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> powerSet(vector<int> origSet);
void powerSet(vector<vector<int>>& allSets, int newItem);
vector<vector<int>> powerSetRecurse(vector<int>& origSet);
vector<vector<int>> powerSetRecurse(vector<int>& origSet, vector<vector<int>>& allSets, int index);

vector<vector<int>> powerSet(vector<int> origSet) {
   vector<vector<int>> allSets({vector<int>()});

   for (int setItem : origSet) {
      powerSet(allSets, setItem);
   }

   return allSets;
}

void powerSet(vector<vector<int>>& allSets, int newItem) {
   vector<vector<int>> copy(allSets);
   
   for (vector<int>& copySet : copy) {
      copySet.push_back(newItem);
   }

   allSets.insert(allSets.end(), copy.begin(), copy.end());
}

vector<vector<int>> powerSetRecurse(vector<int>& origSet) {
   vector<vector<int>> allSets = vector<vector<int>>({vector<int>()});
   return powerSetRecurse(origSet, allSets, origSet.size() - 1);	
}

vector<vector<int>> powerSetRecurse(vector<int>& origSet, vector<vector<int>>& allSets, int index) {
	if (index == -1) {
		return vector<vector<int>>({vector<int>()});
	}

	vector<vector<int>> prevPowerSet = powerSetRecurse(origSet, allSets, index - 1);

	for (vector<int>& innerSet : prevPowerSet) {
		innerSet.push_back(origSet[index]);
	}

	allSets.insert(allSets.end(), prevPowerSet.begin(), prevPowerSet.end());

	return allSets;
}

int main() {
   vector<int> origSet({1, 2, 3, 4});

   vector<vector<int>> allSetsIter = powerSet(origSet);
   vector<vector<int>> allSetsRecurse = powerSetRecurse(origSet);

   for (vector<int> singleSet : allSetsIter) {
      for (int setItem : singleSet) {
         cout << setItem << " ";
      }
      cout << endl;
   }

   cout << endl;

   for (vector<int> singleSet : allSetsRecurse) {
      for (int setItem : singleSet) {
         cout << setItem << " ";
      }
      cout << endl;
   }
}

/*
1 2 3

1
2
3

1 2
1 3
2 3


1 2 3 4

1
2
3
4*

1 2
1 3
2 3
1 4*
2 4*
3 4*

1 2 3
1 2 4*
1 3 4*
2 3 4*


1 2 3 4 5

1
2
3
4
5*

1 2
1 3
1 4
2 3
2 4
3 4
1 5*
2 5*
3 5*
4 5*

1 2 3
1 2 4
1 3 4
2 3 4
1 2 5*
1 3 5*
1 4 5*
2 3 5*
2 4 5*
3 4 5*

1 2 3 4
1 2 3 5*
1 2 4 5*
1 3 4 5*
2 3 4 5*
...
*/



