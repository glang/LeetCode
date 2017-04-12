def IsUnique(s):
	unique = set()

	for x in s:
		if x in unique:
			return False
		unique.add(x)

	return True

print(IsUnique("hello"))
print(IsUnique("helo"))