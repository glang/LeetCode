def oneAway(s1, s2):
   found_edit = False
   length_diff = abs(len(s1) - len(s2))
   i1, i2 = 0, 0

   if length_diff > 1:
      return False

   while i1 < len(s1) and i2 < len(s2):
      if s1[i1] != s2[i2]:
         if found_edit:
            return False
         
         found_edit = True
         
         if length_diff > 0:
            if len(s1) > len(s2):
               i2 -= 1
            else:
               i1 -= 1         
      i1 += 1
      i2 += 1

   return True

assert oneAway('same', 'same') == True
assert oneAway('same', 'sane') == True
assert oneAway('same', 'sanee') == False
assert oneAway('same', 'seee') == False

