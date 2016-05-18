vector<list<shared_ptr<Node>>> listOfDepths(shared_ptr<Node> root) {
	vector<list<shared_ptr<Node>>>> lists;
	insert(lists, root, 0);
	return lists;
}

void insertNode(vector<list<shared_ptr<Node>>> &lists, shared_ptr<Node> node, int depth) {
	if (node == nullptr) {
		return;
	}

	if (lists.size() - 1 < depth) {
		lists.push_back(list<shared_ptr<Node>>());
	}

	list[depth].push_back(node);
	insertNode(lists, node->left, depth + 1);
	insertNode(lists, node->right, depth + 1);
}

/*
        o
    o        o
   o o      o o
  o
 o
*/