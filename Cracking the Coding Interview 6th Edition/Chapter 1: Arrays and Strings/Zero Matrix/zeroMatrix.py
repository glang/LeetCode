def zeroMatrix(m):
	z_rows, z_cols = set(), set()

	for i in range(len(m)):
		for j in range(len(m[0])):
			if m[i][j] == 0:
				z_rows.add(i)
				z_cols.add(j)

	for i in range(len(m)):
		for j in range(len(m[0])):
			if i in z_rows or j in z_cols:
				m[i][j] = 0	

m = [[1 for x in range(10)] for y in range(10)]
m[3][4] = 0

zeroMatrix(m)

for x in m:
	print(x)