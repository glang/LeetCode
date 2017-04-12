def IsPerm1(s1, s2):
	ss1 = ''.join(sorted(list(s1)))
	ss2 = ''.join(sorted(list(s2)))
	return ss1 == ss2

def IsPerm2(s1, s2):
	d1, d2 = {}, {}

	for x in s1:
		d1[x] = d1.get(x, 0) + 1
	for y in s2:
		d2[y] = d2.get(y, 0) + 1
	return d1 == d2

print(IsPerm1("abc", "abc"))
print(IsPerm2("abc", "abc"))
print(IsPerm2("abc", "abd"))