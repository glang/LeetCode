def min_BST(l):
	center_idx = len(l)//2
	root = Node(center_idx)
	helper(l, root, 0, center_idx - 1)
	helper(l, root, center_idx + 1, len(l) - 1)
	return root

def helper(l, parent, start, end):
	if start <= end:
		center_idx = (start + end) // 2
		new_node = Node(l[center_idx])

		if parent.data > new_node.data:
			parent.left = new_node
			helper(l, new_node, start, center_idx - 1)
		else:
			parent.right = new_node
			helper(l, new_node, center_idx + 1, end)