/*

       5
   2       8
  1 3     7 9
     4   6

-might not have successor
-might not have right node to find min in subtree
-might be root and not have parent

*/

Node* successor(Node* node) {
	if (node->right != null) {
		return findMin(node->right);
	} else {
		Node* up = findGreaterUp(node);

      if (up == nullptr) {
         return nullptr;
      } else {
         return up;   
      }
	}
}

Node* findMin(Node* node) {
	Node* min = node;

	while (min != nullptr) {
		min = min->left;
	}

	return min;
}

Node* findGreaterUp(Node* node) {
   Node* iter = node;

   while (iter != null && iter->data < node->data) {
      iter = iter->parent;
   }

   return iter;
}