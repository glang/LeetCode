/*

A -> B -> C -> D -> E -> C*

*/

//O(N) time and O(N) space solution
Node* loopDetection(Node *head) {
	unordered_set<Node*> nodes;
	Node *iter = head;
	
	while (nodes.find(iter) == nodes.end()) {
		nodes.insert(iter);
		iter = iter->next;
	}

	return iter;
}