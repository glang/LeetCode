def IsUnique(s):
	sorted_s = ''.join(list(s))
	for i in range(len(sorted_s)-1):
		if sorted_s[i] == sorted_s[i + 1]:
			return False
	return True

print(IsUnique("hello"))
print(IsUnique("helo"))