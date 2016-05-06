//shift all Node data toward the head via copying
void deleteMiddleNode(shared_ptr<Node> node) {
	shared_ptr iter = node;
	while (iter->next->next) {
		iter->val = iter->next->val;
		iter = iter->next;
	}

	iter->next = 0;
}