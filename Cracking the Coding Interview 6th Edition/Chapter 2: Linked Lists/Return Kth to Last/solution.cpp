//Two runs. First to find length
int kthToLast1(int k, shared_ptr<Node> head) {
	int length = 0;
	auto iter = head;

	while (iter) {
		++count;
		iter = iter->next;
	}

	auto kth = head;
	for (int i = 0; i < length - k; ++i) {
		kth = kth->next;
	}

	return kth->val;
}

//One run, using a list to keep track of k nodes
int kthToLast2(int k, shared_ptr<Node> head) {
	list<int> knodes;
	
	while (iter) {
		if (knodes.size()) {
			knodes.pop_front();
		}
		
		knodes.push_back(iter->val);
		iter = iter->next;
	}

	return knodes.front();
}
