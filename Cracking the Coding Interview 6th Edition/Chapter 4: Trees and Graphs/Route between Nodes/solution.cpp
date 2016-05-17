bool hasRoute(shared_ptr<Node> A, shared_ptr<Node> B) {
	if (!A || !B) {
		return false;
	}

	if (A == B) {
		return true;
	}

	queue<shared_ptr<Node>> nodes;
	nodes.push_back(A);
	A->visited = true;

	while (!nodes.isEmpty()) {
		shared_ptr<Node> curNode = nodes.front();
		nodes.pop_front();

		for (shared_ptr<Node> adjNode : curNode->adj) {
			if (!adjNode->visited) {
				if (adjNode == B) {
					return true;
				} else {
					nodes.push_back(adjNode);
					adjNode->visited = true;
				}
			}
		}
	}

	return false;
}