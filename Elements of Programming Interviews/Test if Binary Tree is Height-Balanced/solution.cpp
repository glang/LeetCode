/*
         5
     2        8
   1   3    7   9

*/

int getHeight(Node* node) {
	if (!node) {
		return -1;
	}

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);

	if (leftHeight == -2 || rightHeight == -2) {
		return -2;
	}

	if (abs(leftHeight - rightHeight) > 1) {
		return -2;
	} else {
		return 1 + max(leftHeight, rightHeight);
	}
}

bool checkBalanced(Node* root) {
	return getHeight(root) != -2;
}