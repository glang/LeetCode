/*
note: A BST doesn't JUST have the property of leftVal <= midVal < rightVal

    5
  3   7
 1 4 6  8

*/

bool validateBST(Node *node, int parentVal) {
	if (node == nullptr) {
		return true;
	}

	if (node->left != nullptr) 
		if (node->left->val > node->val || (node->val > parentVal && node->left->val < parentVal)) {
			return false;
		}
	}

	if (node->right != nullptr)
		if (node->right->val >= node->val || (node->val < parentVal && node->right->val > parentVal)) {
			return false;
		}
	}

	return validateBST(node->left, node->val) && validateBST(node->right, node->val);
}