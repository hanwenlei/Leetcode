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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* result = NULL;
    	
    	if(l1 == NULL)
    	{
    		return l2;
		}
		if(l2 == NULL)
		{
			return l1;
		}
    	
        if(l1->val < l2->val)
        {
        	result = new ListNode(l1->val);
        	l1 = l1->next;
		}
		else
		{
			result = new ListNode(l2->val);
			l2 = l2->next;
		}
		
		ListNode* temp = result;
		while(l1 != NULL || l2 != NULL)
		{
			if(l1 == NULL)
			{
				temp->next = l2;
				break;
			}
			if(l2 == NULL)
			{
				temp->next = l1;
				break;
			}
			
			if(l1->val < l2->val)
			{
				temp->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else
			{
				temp->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			temp = temp->next;
		}
		
		return result;
    }
};
