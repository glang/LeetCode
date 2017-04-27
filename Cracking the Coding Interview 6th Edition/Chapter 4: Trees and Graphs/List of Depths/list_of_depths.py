def list_of_depths_recursive(root):
	l = []
	helper(l, 0, root)
	return l

def helper(l, level, node):
	if node is not None:
		if level > len(l) - 1:
			l.append(ListedList())
		l[level].append(node.data)
		helper(l, level + 1, node.left)
		helper(l, level + 1, node.right)

def list_of_depths_interative(root):
	l = []
	level = 0
	cur_level = [root]

	while not cur_level:
		next_level = []
		l.append(LinkedList())
		for x in cur_level:
			l[level].append(x.data)
			next_level.append(x)
		level += 1
		cur_level = next_level

	return l