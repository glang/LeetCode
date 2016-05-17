bool BFS(shared_ptr<Node> root, int val) {
	queue<shared_ptr<Node>> nodes({root});

	while (!queue.isEmpty()) {
		shared_ptr<Node> cur = nodes.front();
		nodes.pop_front();

		if (cur->val == val) {
			return true;
		}

		for (shared_ptr<node> adj : cur->adj) {
			if (!adj->visited) {
				nodes.push_back(adj);
				adj->visited = true;
			} 
		}
	}

	return false;
}

/*

            o
        o       o
       o o     o o
*/