def valid_BST_in_order(root):
	last_val = None
	return helper(root)

def helper(node):
	if node is None:
		return True
	if not helper(node.left):
		return False
	if last_val is not None and last_val > node.data:
		return False
	last_val = node.data
	if not helper(node.right):
		return False
	return True

def valid_BST_2(root):
	return helper2(None, root):

def helper2(parent, cur):
	if cur is None:
		return True
	if cur.left is not None:
		if cur.left.data > cur.data:
			return False
		if parent is not None and cur is parent.right and cur.left.data <= parent.data:
			return False
	if cur.right is not None:
		if cur.right.data < cur.data:
			return False
		if parent is not None and cur is parent.left and cur.right.data > parent.data:
			return False
	return helper2(cur, cur.left) and helper2(cur, cur.right)