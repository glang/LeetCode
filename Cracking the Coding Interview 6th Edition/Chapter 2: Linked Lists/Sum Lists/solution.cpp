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

/*
sum lists

9 9 9
2 1
*/

typedef shared_ptr<Node> sp;

void sumListsRecurse(list<sp> result, sp Anode, sp Bnode, int prevcarry) {
	if (Anode == nullptr && Bnode == nullptr && carry == 0) {
		return;
	}

   int sum = prevcarry;

   if (Anode != nullptr) {
      sum += Anode->val;
   }

   if (Bnode != nullptr) {
      sum += Bnode->val;
   }

   int carry = 0;

   if (sum > 9) {
   	carry = 1;
   	sum = sum - 10;
   }

   result.push_back(Node(sum));
   sumLists(result, Anode != nullptr ? Anode->next : nullptr, Bnode != nullptr ? Bnode->next : nullptr, carry);
}























