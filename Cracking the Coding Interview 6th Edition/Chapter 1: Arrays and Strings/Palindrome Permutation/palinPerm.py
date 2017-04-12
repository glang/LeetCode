def palinPermFreqCount(s):
   d = {}

   for x in s:
      d[x] = d.get(x, 0) + 1

   numOdds = 0

   for x in d.values():
      if x%2 == 1:
         numOdds += 1

   return numOdds <= 1

'''
print(palinPermFreqCount("aabaa"))
print(palinPermFreqCount("aabbaa"))
print(palinPermFreqCount("aaba"))
'''

def palinPermSort(s):
   numOdds = 0

   if len(s) <= 1:
      return True

   s.sort()
   count = 1
   for i in range(1, len(s)):
      if s[i - 1] == s[i]:
         count += 1
      else:
         if count%2 == 1:
            numOdds += 1
         count = 1
   
   if count%2 == 1:
      numOdds += 1

   print(s)
   print(numOdds)
   return numOdds <= 1

print(palinPermSort(list("aabaa")))
print(palinPermSort(list("aabbaa")))
print(palinPermSort(list("aaba")))
print(palinPermSort(list("aabc")))
print(palinPermSort(list("aabbc")))