def successor(node):
	if node is None:
		return None
	if node.right is not None:
		iter_down = node.right
		while iter_down.left is not None:
			iter_down = iter_down.left
		return iter_down
	else:
		iter_up = node
		while iter_up.parent is not None:
			if iter_up is iter_up.parent.left:
				return iter_up.parent
			iter_up = iter_up.parent
		return None

