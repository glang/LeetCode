/*
	sort a stack such that the smallest element is on top. Can use a temp stack.

14 1 9 3 6

---
14 1 9 3
6
---
3 < 6
14 1 9
6 3
--
9 > 3 and 6
put 9 in temp var
push 3 and 6 back in old stack
push 9 in holder


make the second stack sorted in reverse, then push all elements back to original stack

*/

void sortStack(stack<int>& stack) {
	stack<int> holder;
	int temp;

	while (!stack.empty()) {
		temp = stack.top();
		if (holder.empty() || holder.top > temp) {
			holder.push(stack.top());
			stack.pop();
		} else {

		}
	}

}