void removeDups(shared_ptr<Node> head) {
	unordered_set<int> unique;

	shared_ptr<Node> iter = head;
	
	while (iter->next) {
		int nextVal = iter->next->val;
		if (unique.find(nextVal) != unique.end()) {
			iter->next = iter->next->next;
		} else {
			unique.insert(nextVal);
		}

		iter = iter->next;
	} 
}