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
//   if (node->parent == nullptr && node->right == nullptr) {
//      return null;
//   }

	if (node->right != null) {
		return findMin(node->right);
	} else {
		Node* up = findGreaterUp(node);

      if (up == nullptr) {
         return nullptr;
      } else if (up->right == nullptr) {
         return up;
      } else {
         Node* minNode = findMin(up->right);
         return minNode->data < up->data ? minNode : up;      
      }
	}
}

Node* findMin(Node* node) {
	Node* min = node;
	Node* iter = node;

	while (iter != nullptr) {
		min = iter;
		iter = iter->left;
	}

	return min;
}

Node* findGreaterUp(Node* node) {
   Node* iter = node;

   while (iter->data < node->data || node->parent != nullptr) {
      iter = iter->parent;
   }

   return iter;
}