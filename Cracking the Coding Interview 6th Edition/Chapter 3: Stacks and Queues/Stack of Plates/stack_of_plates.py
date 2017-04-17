class StackOfPlates:
	def __init__(self, threshold):
		self.threshold = threshold
		self.stacks = []

	def push(self, data):
		if not self.stacks or self.stacks[-1].size() == threshold:
			self.stacks.append(Stack())
		self.stacks[-1].push(data)

	def pop(self):
		if not self.stacks:
			raise Exception()
		ret = self.stacks[-1].pop()

		if self.stacks[-1].empty():
			self.stacks.pop()
		return ret
