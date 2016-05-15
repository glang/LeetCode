bool stringRotation(string s1, string s2) {
	int s1Index = 0;
	int s2Index = 0;

	while (s1Index < s1.size()) {
		if (s1[s1Index] == s2[s2index]) {
			++s2Index;
		} else {
			s2Index = 0;
		}

		++s1Index;
	}

	if (s2Index == s2.size) {
		return true;
	}

	return s2.substring(s2Index - 1) == s1.substring(0, s2Index);
}

/*
waterbottle
bottlewater

waterwaterd
waterdwater
*/