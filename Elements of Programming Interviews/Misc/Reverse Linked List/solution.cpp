#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;

	Node() {};
	Node(int d, Node *n) : data(d), next(n) {};
};

Node* reverseLinkedListIter(Node *head) {
	Node *prev = nullptr, *cur = head;

	while (cur != nullptr) {
		Node* curNext = cur->next;
		cur->next = prev;
		prev = cur;
		cur = curNext;
	}

	return prev;
}

void recurseHelper(Node *node) {
	if (node->next != nullptr) {
		recurseHelper(node->next);
		node->next->next = node;
	}
}

void reverseLinkedListRecurse(Node *head) {
	recurseHelper(head);
	head->next = nullptr;
}


int main() {
	Node a, b, c;
	a = Node(1, &b);
	b = Node(2, &c);
	c = Node(3, nullptr);

/*
	Node *r = reverseLinkedListIter(&a);

	while (r != nullptr) {
		cout << r->data << endl;
		r = r->next;
	}
*/

	reverseLinkedListRecurse(&a);
	Node *r = &c;

	while (r != nullptr) {
		cout << r->data << endl;
		r = r->next;
	}

	return 0;
}