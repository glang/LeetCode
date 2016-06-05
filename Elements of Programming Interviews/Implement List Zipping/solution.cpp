#include <list>
#include <iostream>

using namespace std;

/*
1 -> 2 -> 3 -> x

3 -> 2 -> 1 -> x
*/

/*
list<int> zipList(list<int> inList) {
	list<int> outList;
	for (auto i = inList.begin(); i < (inList.begin() + inList.size()) / 2; ++i) {
		outList.push_back(*i);
		outList.push_back(inList.begin() + (inList.size() - (i - inList.begin()) - 1)); 
	}

	if (inList.size() % 2 == 1) {
		inList.push_back(inList.begin() + inList.size()/2 + 1);
	} 

	return outList;
}
*/

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
}