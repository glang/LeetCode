shared_ptr<Node> partition(shared_ptr<Node> head, int splitVal) {
	shared_ptr<Node> iter = head;

	while (iter->next) {
		if (iter->next->val < splitVal) {
			shared_ptr<Node> next = iter->next->next;
			iter->next->next = head->next;
			head->next = next;
			iter->next = head;
			*head = iter->next;
		}

		iter = iter->next;
	}

	return head;
}

//3 -> 2 -> 1
