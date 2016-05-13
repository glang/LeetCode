//1 2 3
/*

*/

void powerSet(set<int> origSet) {
	vector<set<int>> allSets{set<int>()};
	powerSet(origSet, allSets, origSet.size(), 0);
}

void powerSet(set<int> origSet, set<set<int>> allSets, int count, int start) {
	
}

