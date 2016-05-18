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

vector<list<shared_ptr<Node>>> listOfDepthsIter(shared_ptr<Node> root) {
	vector<list<shared_ptr<Node>>>> lists;

	list<shared_ptr<Node>> current;
	current.push_back(root);
	lists.push_back(current);

	while (current.size() > 0) {
		list<shared_ptr<Node>> next;

		for (shared_ptr<Node> node : current) {
			if (node->left != nullptr) {
				next.push_back(node->left);
			}

			if (node->right != nullptr) {
				next.push_back(node->right);
			}
		}

		lists.push_back(next);
		current = next;
	}

	return lists;
}

/*
        o
    o        o
   o o      o o
  o
 o
*/