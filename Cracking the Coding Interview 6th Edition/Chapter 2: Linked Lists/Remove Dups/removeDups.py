def removeDups(ll):
   unique = {ll.head.data}

   iter = ll.head

   while iter.next is not None:
      if iter.next.data in unique:
         iter.next = iter.next.next
      else:
         iter = iter.next