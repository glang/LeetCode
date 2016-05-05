#include <memory>
#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> next;

	Node(int newVal) : val(newVal) {}
};

void removeDups(shared_ptr<Node> head) {
	//if head is null then return
	//two implementations. One with one iterator, the other with two
/*
	unordered_set<int> unique({head->val});
	shared_ptr<Node> iter = head;
	
	while (iter->next) {
		int nextVal = iter->next->val;
		if (unique.find(nextVal) != unique.end()) {
			iter->next = iter->next->next;
		} else {
			unique.insert(nextVal);
			iter = iter->next;
		}
	} 
*/

	auto prevIter = head;
	auto curIter = head->next;
	unordered_set<int> unique({head->val});

	while (curIter) {
		if (unique.find(curIter->val) != unique.end()) {
			prevIter->next = curIter->next;
		} else{
			unique.insert(curIter->val);
			prevIter = prevIter->next;
		}

		curIter = curIter->next;
	}
}

int main() {
	auto head = make_shared<Node>(1);
	auto node2 = make_shared<Node>(2);
	auto node3 = make_shared<Node>(2);
	auto node4 = make_shared<Node>(3);
	auto node5 = make_shared<Node>(2);
	auto node6 = make_shared<Node>(3);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	removeDups(head);

	auto iter = head;
	while (iter) {
		cout << iter->val << endl;
		iter = iter->next;
	}
}