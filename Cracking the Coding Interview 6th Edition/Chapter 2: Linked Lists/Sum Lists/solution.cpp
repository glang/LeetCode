list<int> sumList(list<int> A, list<int> B) {
	int carry = 0;
	list<int> result;
	list<int>::iterator aIter = A.begin();
	list<int>::iterator bIter = B.begin();

	while (aIter != A.end() && bIter != b.end()) {
		int sum = carry;

		if (aIter != A.end()) {
			sum += *aIter;
			++aIter;
		}

		if (bIter != B.end()) {
			sum += *bIter;
			++bIter;
		}

		if (sum > 9) {
			carry = 1;
			result.push_back(sum - 10);
		} else {
			carry = 0;
			result.push_back(sum);
		}
	}

	if (carry == 1) {
		result.push_back(1);
	}

	return result;
}

/*
9 9 9
1
0 0 0 1

9 9 9 
1
1 0 0 0
*/