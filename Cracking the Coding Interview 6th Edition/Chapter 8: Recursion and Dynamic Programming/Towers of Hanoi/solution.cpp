#include <stack>
#include <iostream>

using namespace std;

/*

brainstorm:

move 4 3 2 1 from first to third tower 
	move 3 2 1 from first to second tower 
		move 2 1 from first to third tower
			move 1 from the first to second tower
	move 4  from first to third tower
	move 3 2 1 from second to third tower
		move 2 1 from second to third tower
			move 1 from the second to second tower
-4 3 2 1
-
-

-4 3 2
-1
-

-4 3 
-1
-2

-4 3 
-
-2 1 

-4  
-3
-2 1

-4 1 
-3
-2 

-4 1 
-3 2
- 

-4
-3 2 1 
- 

-
-3 2 1 
-4 

*/

void moveDisk(stack<char> &source, stack<char> &dest, stack<char> &holder, int numDisks) {
	if (numDisks == 0) {
		return;
	}

	if (numDisks > 1) {
		moveDisk(source, holder, dest, numDisks - 1);
	}

	char toMove = source.top();
	source.pop();
	dest.push(toMove);

	moveDisk(holder, dest, source, numDisks - 1);
}

int main() {
	stack<char> one, two, three;
	one.push('C');
	one.push('B');
	one.push('A');

	moveDisk(one, three, two, 3);

	cout << three.top() << endl;
	three.pop();
	cout << three.top() << endl;
	three.pop();
	cout << three.top() << endl;
	three.pop();
}