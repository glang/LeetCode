class Min_Stack:
	def __init__(self):
		self.items = []

	def push(self, data):
		min_item = None

		if not self.items:
			min_item = data
		else:
			min_item = min(data, self.items[-1][1])

		self.items.append((data, min_item))

	def pop(self):
		if not self.items:
			raise Exception('Empty stack!')
		ret = self.items[-1]
		del self.items[-1]
		return ret

	def min(self):
		if not self.items:
			raise Exception('Empty stack!')
		return self.items[-1][1]

ms = Min_Stack()
ms.push(3)
ms.push(1)
ms.push(5)
ms.push(4)
print(ms.min())
ms.pop()
print(ms.min())
ms.pop()
ms.pop()
print(ms.min())
ms.push(0)
print(ms.min())