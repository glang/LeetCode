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

void powerSet(set<int> origSet) {
	vector<set<int>> allSets{set<int>()};
	powerSet(origSet, allSets, origSet.size(), 0);
}

void powerSet(set<int> origSet, set<set<int>> allSets, int count, int start) {
	
}

