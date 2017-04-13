def rotateMatrix(m):
   for l in range(len(m)//2):
      for i in range(len(m) - 1 - l * 2):
         m[l][l + i], m[l + i][len(m) - 1 - l] = m[l + i][len(m) - 1 - l], m[l][l + i]
         m[l][l + i], m[len(m) - 1 - l][len(m) - 1 - l - i] = m[len(m) - 1 - l][len(m) - 1 - l - i], m[l][l + i]
         m[l][l + i], m[len(m) - 1 - l - i][l] = m[len(m) - 1 - l - i][l], m[l][l + i]


m1 = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
m2 = [[0, 1, 2, 3, 4], [5, 6, 7, 8, 9], [10, 11, 12, 13, 14], [15, 16, 17 ,18, 19], [20, 21, 22, 23, 24]]

rotateMatrix(m1)
rotateMatrix(m2)

for i in range(len(m1)):
   print(m1[i])

print()

for j in range(len(m2)):
   print(m2[j])