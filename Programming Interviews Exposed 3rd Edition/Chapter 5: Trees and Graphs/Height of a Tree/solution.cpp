int treeHeight(shared_ptr<Node> node) {
	if (node == 0) {
		return 0;
	} else {
		return 1 + max(treeHeight(node->left), treeHeight(node->right));
	}
}