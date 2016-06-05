list<int> zipList(list<int> inList) {
	list<int> outList;
	for (auto i = inList.begin(); i < (inList.begin() + inList.size()) / 2; ++i) {
		outList.push_back(*i);
		outList.push_back(inList.begin() + (inList.size() - (i - inList.begin()) - 1)); 
	}

	if (inList.size() % 2 == 1) {
		inList.push_back(inList.begin() + inList.size()/2 + 1);
	} 

	return outList;
}