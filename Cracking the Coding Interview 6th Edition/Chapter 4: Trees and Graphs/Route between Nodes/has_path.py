import queue

class GraphNode:
	def __init__(self):
		self.data = None
		self.neighbors = set()
		self.visited = False

def hasPathBFS(n1, n2):
	q = queue.Queue()
	q.put(n1)

	while q.qsize() > 0:
		cur = q.get()
		cur.visited = True
		for x in cur.neighbors:
			if x is n2:
				return True
			if not x.visited:
				q.put(x)

	return False

def hasPathDFS(n1, n2):
	if n1 is n2:
		return True
	if not n1.visited:
		n1.visited = True
		for x in n1.neighbors:
			if hasPathDFS(x, n2):
				return True
	return False

def reset(l):
	for x in l:
		x.visited = False
n1, n2, n3 = GraphNode(), GraphNode(), GraphNode()
nodes = [n1, n2, n3]
n1.neighbors.add(n2)
print(hasPathBFS(n1, n2))
reset(nodes)
print(hasPathBFS(n1, n3))
reset(nodes)
print(hasPathBFS(n2, n3))
reset(nodes)
print(hasPathDFS(n1, n2))
reset(nodes)
print(hasPathDFS(n1, n3))
reset(nodes)
print(hasPathDFS(n2, n3))