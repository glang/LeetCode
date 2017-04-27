def valid_BST_in_order(root):
	last_val = None
	return helper(root)

def helper(node):
	if node is None:
		return True
	if not helper(node.left):
		return false
	if last_val is not None and last_val > node.data:
		return false
	last_val = node.data
	if not helper(node.right):
		return false
	return True