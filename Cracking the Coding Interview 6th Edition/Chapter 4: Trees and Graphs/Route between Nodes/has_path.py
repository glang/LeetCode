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

		for x in cur.neighbors:
			if x is n2:
				return True
			if not x.visited:
				q.put(x)

	return False

n1, n2, n3 = GraphNode(), GraphNode(), GraphNode()
n1.neighbors.add(n2)
print(hasPathBFS(n1, n2))
print(hasPathBFS(n1, n3))
print(hasPathBFS(n2, n3))