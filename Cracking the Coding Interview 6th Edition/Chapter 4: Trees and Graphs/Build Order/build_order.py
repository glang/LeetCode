def build_order(p, dep):
	order = []
	dict = {}

	for x in p:
		dict[x] = set()
	for x in dep:
		dict[x[1]].add(x[0])

	while dict:
		target = None
		for x in dict.items():
			if not x[1]:
				target = x[0]
				break
		if target is None:
			return None
		for x in dict.values():
			if target in x:
				x.remove(target)
		order.append(target)
		dict.pop(target)
	return order

p = list('abcdef')
dep = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c')]
print(build_order(p, dep))
