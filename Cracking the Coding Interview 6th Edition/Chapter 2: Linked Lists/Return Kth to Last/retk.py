def ret_k_to_last(ll, k):
   k_ahead = ll.head

   for i in range(k):
      k_ahead = k_ahead.next

   k_behind = ll.head

   while k_ahead is not None:
      k_ahead = k_ahead.next
      k_behind = k_behind.next

   return k_behind

def rktl_recurse(ll, k, node):
   if node.next is None:
      return 1

   val = 1 + rktl_recurse(ll, k, node.next)
   if val == k:
      print(node.data)

   return val
