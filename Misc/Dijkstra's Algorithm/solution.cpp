/*

1. set all node distances other than source to infinity and source as 0.
2. starting at the source, visit adjacent nodes and mark them with the distance from current node. If a adjacent node has a distance labled that is larger than a new distance the current node can provide, replace that distance.
3. mark current node as visited

*/

struct GraphNode {
	int distance;
	bool done;
	vector<int> adjIdx;	
	vector<int> weights;
};

void dijkstra(Graph graph, int curNodeIdx) {
	GraphNode *cur = graph[curNodeIdx];

	for (int idx : cur->adj) {
		GraphNode *adj = graph[idx];
		if (!adj->done && adj->distance > cur->distance + cur->weight[idx]) {
			adj->distance = cur->distance + cur->weight[idx];
		}
	}

	cur->done = true;

	for (int idx : cur->adj) {
		if (!adj->done) {
			dijkstra(graph, idx);
		}
	}
}