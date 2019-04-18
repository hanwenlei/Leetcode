#include<iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
        	return head;
		}
		ListNode* temp1 = head;
		ListNode* temp2 = head;
		while(n--)
		{
			temp1 = temp1->next;
		}
		if(temp1 == NULL)
		{
			return head->next;
		}
		else
		{
			while(temp1->next != NULL)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			temp2->next = temp2->next->next;
		}
		return head;
    }
};
