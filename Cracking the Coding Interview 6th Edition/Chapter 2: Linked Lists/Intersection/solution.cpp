/*

A -> B 
       \
         -> C -> D -> null
       /
     G

Ideas: 
O(N^2) time and O(1) space solution: for every element in one list, compare it to every element in the second list
O(N) time and space solution: store elements of both lists into vectors. Starting from the end of both lists, find element in common
O(N) time and O(1) space solution: find the length of both linked lists. If there is an intersection, then the last elements of the two lists will be the same. Advance the longer list by the differnece of length between the two lists, then compare element by element

*/

Node* intersection(Node *A, Node *B) {
	int Alength = getLength(A);
	int Blength = getLength(B);
	int diff = Alength - Blength;

	if (Alength > Blength) {
		for (int i = 0; i < diff; ++i) {
			A = A->next;
		}
	} else {
		for (int i = 0; i < diff; ++i) {
			B = B->next;
		}	
	}

	while (A != nullptr) {
		if (A == B) {
			return A;
		}

		A = A->next;
		B = B->next;
	}

	return null;
}

