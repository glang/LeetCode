//copy data from next node, then delete next node
void deleteMiddleNode(shared_ptr<Node> node) {
	node->val = node->next->val;
	node->next = node->next->next;
}