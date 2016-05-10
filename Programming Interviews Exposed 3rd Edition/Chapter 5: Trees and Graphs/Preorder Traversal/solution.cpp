void print_preorder(shared_ptr<Node> node) {
	if (node == 0) {
		return;
	}

	cout << node->data << endl;
	print_preorder(node->left);
	print_preorder(node->right);
}

void print_preorder(shared_ptr<Node> node) {
	if (node == 0) {
		return;
	}

	stack<shared_ptr<Node>> stack{node};

	while (!stack.isEmpty()) {
		shared_ptr<Node> iter = stack.top();
		stack.pop();

		while (iter != 0) {
			cout << iter->data;
			if (iter->right) {
				stack.push(iter->right);
			}

			iter = iter->left;
		}
	}
}

              z
         z         z
       z   z     z   z
      z z z z   z z z z