#include <vector>
#include <iostream>

using namespace std;

/* 
idea: two pointer technique. One goes twice each time the other goes once
so when the second hits the end, the first is in the middle. While the first 
is going, add values into a list.

A -> B -> C -> B -> A
A -> B -> B -> A

*/

bool palindrome(Node *head) {
	Node *first = head, Node *second = head;

	if (head == nullptr) {
		return true;
	}

	vector<char> items;
	while (second != nullptr) {
		items.push_back(first->data);
		first = first->next;

		if (second->next != null) {
			second = second->next->next;
		} else {
			second = nullptr;

			if (first == nullptr) {
				return true;
			}

			first = first->next;
		}
	}


	for (int i = items.size() - 1; i <= 0; --i) {
		if (first.data != items[i]) {
			return false;
		}

		first = first->next;
	}

	return true;
}