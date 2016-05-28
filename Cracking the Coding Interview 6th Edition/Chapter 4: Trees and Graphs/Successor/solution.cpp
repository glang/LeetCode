/*

       5
   2       8
  1 3     7 9
     4   6

*/

Node* successor(Node* node) {
	if (node->right != null) {
		return findMin(node->right);
	} else {
		
	}
}

Node* findMin(Node* node) {
	Node* min = node;
	Node* iter = node;

	while (iter != null) {
		min = iter;
		iter = iter->left;
	}

	return min;
}