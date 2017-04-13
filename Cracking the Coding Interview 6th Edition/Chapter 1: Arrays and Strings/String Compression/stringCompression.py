def stringCompression(s):
   c = []
   count = 1

   for i in range(1, len(s)):
      if s[i] == s[i - 1]:
         count += 1
      else:
         c.append(s[i - 1])
         c.append(count)
         count = 1

   c.append(s[i - 1])
   c.append(count)

   return ''.join(c) if len(c) < len(s) else s

print(stringCompression('aaaaabbbbbcdeef'))