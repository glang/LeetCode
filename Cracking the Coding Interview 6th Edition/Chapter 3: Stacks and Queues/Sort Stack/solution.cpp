/*
sort a stack such that the smallest element is on top. Can use a temp stack.

make the second stack sorted in reverse, then push all elements back to original stack:

5 4 9 3    6

---
5 4 9      6
3
---
5 4        9
3 6
---
5          4
3 6 9
---
5 9 6      4
3
--
5 9        6
3 4
--
5          9
3 4 6 
--
           5          
3 4 6 9
--
9 6        5          
3 4 
--

Another approach (insertion sort?):
5 4 9 3    6

---
5 4 9      3
6
---
5 4 9 6 3

---
5 4 9 6
3
---
5          4 
3 6 9
---
5 9 6      4 
3
---
5 9 6 4 3

---
.
.
.

*/

void sortStack(stack<int>& stack) {
   stack<int> holder;
   int numElements = stack.size();
   int temp = stack.top();
   stack.pop();

   while (holder.size() != numElements) {
      if (!stack.empty()) {
         int top = stack.top();
         if (top >= temp) {
            holder.push(temp);
            temp = top;
            stack.pop();
         } else {
            if (holder.empty() || holder.top() < top) {
               holder.push(top);
               stack.pop();
            } else {
               holder.push(temp);
               stack.pop();
               temp = top;
               moveItems(holder, stack, temp);
            }
         }
      } else {
         holder.push(temp);
      }
   }

   moveItems(holder, stack, INT_MIN);
}

void moveItems(stack<int> &source, stack<int> &dest, int compare) {
	while (!source.isEmpty() && source.top() > compare) {
		dest.push(source.top());
		source.pop();
	}
}
































