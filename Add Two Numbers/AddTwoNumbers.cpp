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
	ListNode* reverse(ListNode* nodePtr) {
		if (nodePtr->next == NULL)
			return nodePtr;

		reverse(nodePtr->next);
		nodePtr->next->next = nodePtr;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* temp = l1;

		while (l1) {
			cout << l1->val << endl;
			l1 = l1->next;        
		}

		l1 = reverse(temp);

		while (l1) {
			cout << l1->val << endl;
			l1 = l1->next;        
		}

		return 0;
    }
};

// [] -> [] -> [] ->