/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void reverse(ListNode* nodePtr, ListNode* newHead&) {
		if (nodePtr->next == NULL) {
			newHead = nodePtr;
			return;
		}

		reverse(nodePtr->next);
		nodePtr->next->next = nodePtr;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* rl1, rl2;

		reverse(l1, rl1); // l1 is new head of reversed list
		l1->next = NULL; //setting the end of linked list to NULL
		reverse(l2, rl2);
		l2->next = NULL;

		return 0;
    }
};

// [] -> [] -> [] ->