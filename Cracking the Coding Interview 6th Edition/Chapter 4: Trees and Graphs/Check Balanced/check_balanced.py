def check_balanced(node):
	if node is None:
		return -1, True
	left_height = check_balanced(node.left)
	if not left_height[1]:
		return None, False
	right_height = check_balanced(node.right)
	if not right_height[1]:
		return None, False
	if abs(left_height[0] - right_height[0]) > 1:
		return None, False
	return 1 + max(left_height[0], right_height[0]), True