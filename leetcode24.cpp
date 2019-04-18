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
    ListNode *swapPairs(ListNode *head) {
		ListNode* root = new ListNode(0);
		root->next = head;
		ListNode* p1 = root;
		ListNode* p2 = root;
		
		while ( 1 ){
		    if ( p1->next == NULL || p1->next->next == NULL ) break;
			p2 = p2->next->next;     //step 1£ºset pointer p2
			
		    p1->next->next = p2->next; //step 2£ºbegin swap 
			p2->next = p1->next;
			p1->next = p2; 
			
			p2 = p2->next ;            //step 3£ºset pointer p1&&p2
			p1 = p2;
		}
		return root->next;
	}
};
