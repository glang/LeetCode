#include <list>
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

// 1 -- 2 -- 3 -- 4 -- x
// 5 -- 6 -- 7 -- 8 -- x

// 1 -- 2 -- 3 -- 4 -- 5 -- x
// 1 -- 2 -- 3 -- x
// 5 -- 4 -- x

Node* zipList(Node* head) {
	Node *slow = head, *fast = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		if (fast && fast->next) {
		  slow = slow->next;
		}
	}

	if (fast != nullptr) {
		slow = slow->next;
	}

	Node *firstHalfIter = head;
	Node *secHalfIter = reverseLinkedListIter(slow->next);
	slow->next = nullptr;

	while (secHalfIter) {
		auto firstNext = firstHalfIter->next;
		firstHalfIter->next = secHalfIter;
		auto secNext = secHalfIter->next;
		secHalfIter->next = firstNext;
		firstHalfIter = firstNext;
		secHalfIter = secNext;
	}

	return head;
}

int main() {
	Node a, b, c, d;
	a = Node(1, &b);
	b = Node(2, &c);
	c = Node(3, &d);
//	c = Node(3, nullptr);
	d = Node(4, nullptr);

	Node* newHead = zipList(&a);

	while (newHead != nullptr) {
		cout << newHead->data << endl;
		newHead = newHead->next;
	}

	return 0;
}