void removeDups(shared_ptr<Node> head) {
	//if head is null then return
	unordered_set<int> unique({head->val});
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