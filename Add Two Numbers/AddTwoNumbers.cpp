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
    	ListNode *head = 0, *iter;
    	int carry = 0;

    	for (;l1 && l2; l1 = l1->next, l2 = l2->next) {
    		int digit = l1->val + l2->val + carry;

    		if (digit >= 10) {
    			digit -= 10;
    			carry = 1;
    		} else {
    			carry = 0;
    		}

    		if (head == 0) {
    			head = new ListNode(digit);
    			iter = head;
    		} else {
    			iter->next = new ListNode(digit);
    			iter = iter->next;
    		}
    	}

    	ListNode *final = l1 ? l1 : l2;

    	for (;final; final = final->next, iter = iter->next) {
     		int digit = final->val + carry;

    		if (digit >= 10) {
    			digit -= 10;
    			carry = 1;
    		} else {
    			carry = 0;
    		}

			iter->next = new ListNode(digit);
    	}

    	if (carry)
    		iter->next = new ListNode(carry);

    	return head;
    }
};