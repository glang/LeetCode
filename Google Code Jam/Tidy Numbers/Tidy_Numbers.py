def tidy(x):
	if x < 10:
		return x

	for j in range(x, 0, -1):
		s = str(j)
		for k in range(1, len(s)):
			if s[k - 1] > s[k]:
				return tidy(x - 1 - int(s[k:]))
			elif k == len(s) - 1:
				return s 
	return 9

n = int(input())

for i in range(1, n + 1):
	num = int(input())
	res = tidy(num)
	print("Case #{}: {}".format(i, res))