class Node:
	def __init__(self, data, next = None):
		self.data = data
		self.next = next

class LinkedList:
	def __init__(self, head = None):
		self.head = head

	def append(self, data):
		new_node = Node(data)

		if self.head == None:
			self.head = new_node
		else:
			iter = self.head

			while iter.next != None:
				iter = iter.next

			iter.next = new_node

	def print(self):
		iter = self.head
		while iter != None:
			print(iter.data)
			iter = iter.next

	def remove(self, data):
		if self.head is None:
			return
		if self.head.data == data:
			self.head = self.head.next
			return
		iter = self.head
		while iter.next is not None:
			if iter.next.data == data:
				iter.next = iter.next.next
				return
			iter = iter.next

	def reverse_iterative(self):
		iter = self.head
		while iter.next is not None:
			old_head = self.head
			self.head = iter.next
			iter.next = iter.next.next
			self.head.next = old_head

	def reverse_recursive(self, node):
		if node.next is None:
			self.head = node
		else:
			self.reverse_recursive(node.next)
			node.next.next = node
			node.next = None

ll = LinkedList()
ll.append(1)
ll.append(2)
ll.append(3)
ll.append(4)
ll.append(5)
ll.print()
ll.reverse_recursive(ll.head)
ll.print()