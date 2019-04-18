#include<iostream>

using namespace std;

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
        int flag = 0, value = 0;
        value = (l1->val + l2->val + flag) % 10;
        ListNode* temp1 = new ListNode(value);
        flag = (l1->val + l2->val + flag) / 10;
        ListNode* root = temp1;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL && l2 != NULL)
        {
        	value = (l1->val + l2->val + flag) % 10;
        	ListNode* temp2 = new ListNode(value);
        	flag = (l1->val + l2->val + flag) / 10;
        	temp1->next = temp2;
        	temp1 = temp2;
        	l1 = l1->next;
        	l2 = l2->next;
		}
		while(l1 != NULL)
		{
			value = (l1->val + flag) % 10;
        	ListNode* temp2 = new ListNode(value);
        	flag = (l1->val + flag) / 10;
        	temp1->next = temp2;
        	temp1 = temp2;
        	l1 = l1->next;
		}
		while(l2 != NULL)
		{
			value = (l2->val + flag) % 10;
        	ListNode* temp2 = new ListNode(value);
        	flag = (l2->val + flag) / 10;
        	temp1->next = temp2;
        	temp1 = temp2;
        	l2 = l2->next;
		}
		if(flag != 0)
		{
        	ListNode* temp2 = new ListNode(flag);
        	temp1->next = temp2;
		}
		return root;
    }
};
