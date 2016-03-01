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
	void reverse(ListNode* nodePtr, ListNode*& newHead) {
		if (nodePtr->next == NULL) {
			newHead = nodePtr;
			return;
		}

		reverse(nodePtr->next, newHead);
		nodePtr->next->next = nodePtr;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *rl1, *rl2, *ret, *temp = ret;

		reverse(l1, rl1); // l1 is new head of reversed list
		l1->next = NULL; // setting the end of linked list (former head) to NULL
		reverse(l2, rl2);
		l2->next = NULL;

		int carry = 0;

		while (rl1 && rl2) {
			int digit = rl1->next->val + rl2->next->val + carry;

			if (digit > 10) {
				digit -= 10;
				carry = 1;
			} else {
				carry = 0;
			}

			cout << digit << endl;

			ListNode cur = ListNode(digit);
			temp = &cur;
			temp = temp->next;
			rl1 = rl1->next;
			rl2 = rl2->next;
		}

		return ret;
    }
};