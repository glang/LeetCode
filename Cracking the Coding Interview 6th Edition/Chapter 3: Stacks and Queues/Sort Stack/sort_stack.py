def SortStack(stk):
   helper_stk = Stack()

   helper_stk.push(stk.pop())

   while not stk.empty():
      if helper_stk.peek() <= stk.peek():
         helper_stk.push(stk.pop())
      else:
         x = stk.pop()
         while not helper_stk.empty() and helper_stk.peek() > x:
            stk.push(helper_stk.pop())
         helper_stk.push(x)

   while not helper_stk.empty():
      stk.push(helper_stk.pop())