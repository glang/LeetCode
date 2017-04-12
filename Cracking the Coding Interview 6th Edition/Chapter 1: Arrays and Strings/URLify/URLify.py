def URLify(s, n):
	lci = n - 1

	for i in range(n - 1, 0, -1):
		if s[i] != ' ':
			lci = i
			break

	back = len(s) - 1
	for j in range(lci, 0, -1):
		if s[j] == ' ':
			s[back - 2 : back + 1] = '%20'
			back -= 3
		else:
			s[back] = s[j]
			back -= 1

s = list('a b c    ') #'a%20b%20c'
n = 9
URLify(s, n)
print(s)