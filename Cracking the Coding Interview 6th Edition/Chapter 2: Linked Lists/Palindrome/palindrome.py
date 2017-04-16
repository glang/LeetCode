class Node:
	def __init__(self, data, next = None):
		self.data = data
		self.next = next

def palindrome(ll):
	items = []

	while ll is not None:
		items.append(ll.data)
		ll = ll.next

	return items == items[::-1]

a = Node('a')
b = Node('b')
c = Node('c')
d = Node('b')
e = Node('a')
a.next = b
b.next = c
c.next = d
d.next = e
print(palindrome(a))