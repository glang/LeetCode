def sumListsBackwards(n1, n2):
   carry = 0
   head = None
   iter = None
   while n1 is not None or n2 is not None or carry == 1:
      sum = n1.data if n1 is not None + n2.data if n2 is not None + carry

      if sum > 9:
         carry = 1
         sum -= 10
      else:
         carry = 0

      if head is None:
         head = Node(sum)
         iter = head
      else:
         iter.next = Node(sum)
         iter = iter.next

   return head

#not very linked list-ish solution
def sumListsForwards(n1, n2):
   n1_char_list, n2_char_list = [], []

   i1 = n1
   while i1 is not None:
      n1_char_list.append(str(i1.data))

   i2 = n2
   while i2 is not None:
      n2_char_list.append(str(i2.data))

   sum_str = str(int(''.join(n1_char_list)) + int(''.join(n2_char_list)))

   head = Node(sum_str[0])

   iter = head

   for i in range(1, len(sum_str)):
      iter.next = Node(sum_str[i])
      iter = iter.next

   return head

#resursive solution
def sumListsForwardsRecursive(n1, n2):
   result = sumListsForwardsRecursiveHelper(n1, n2)

   if result[1] == 1:
      return Node(1, list[2])
   return list[2] 

def sumListsForwardsRecursiveHelper(n1, n2):
   if n1 is None:
      return [0, 0, None] #sum, carry, node

   list = sumListsForwardsRecursiveHelper(n1.next, n2.next)
   sum = n1.data + n2.data + list[1]

   if sum > 9:
      carry = 1
      sum -= 10
   else
      carry = 0

   digitNode = Node(sum, list[2])
   return [sum, carry, digitNode]
