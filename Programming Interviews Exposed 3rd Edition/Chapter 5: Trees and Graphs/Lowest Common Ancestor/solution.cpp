int lowestCommonAncestor(int first, int second, Node node) {
	int lca = node.data;

	while(node.data != first.data && node.data != second.data) {
	    if (first.data < node.data && second.data < node.data) {
	    	node = first.left;
	    	lca = node.data;
	    } else if (first.data > node.data && second.data > node.data) {
	    	node = first.right;
    		lca = node.data;
	    } else {
	    	return lca;
	    }
	}

	return lca;
}