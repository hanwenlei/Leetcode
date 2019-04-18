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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
        	return NULL;
		}
		else if(head->next == NULL)
		{
			return head;
		}
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* net = head->next;
		while(net != NULL)
		{
			cur->next = pre;
			pre = cur;
			cur = net;
			net = net->next;
		}
		cur->next = pre;
		return cur;
    }
};
