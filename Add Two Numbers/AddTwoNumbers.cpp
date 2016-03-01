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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode prehead(0), *iter = &prehead;
    	int carry = 0;

    	for (;l1 || l2 || carry; l1 = (l1 ? l1->next : 0), l2 = (l2 ? l2->next : 0), iter = iter->next) {
    		int digit = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    		carry = digit >= 10 ? 1 : 0;
			iter->next = new ListNode(digit % 10);
    	}

    	return prehead.next;
    }
};