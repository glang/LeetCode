def partition(ll, x):
   iter = ll.head

   while iter.next is not None:
      if iter.next.data < x:
         new_head = iter.next
         iter.next = iter.next.next
         new_head.next = ll.head
         ll.head = new_head
      else:
         iter = iter.next