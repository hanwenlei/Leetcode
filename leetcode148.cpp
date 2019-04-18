#include<iostream>
#include<vector>
#include<algorithm>

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
    ListNode* sortList(ListNode* head) {
    	if(head == NULL)
    	{
    		return NULL;
		}
        vector<int> num;
        ListNode* temp = head;
        while(temp != NULL)
        {
        	num.push_back(temp->val);
        	temp = temp->next;
		}
		sort(num.begin(), num.end());
		int length = num.size();
		temp = head;
		for(int i = 0; i < length; ++i)
		{
			temp->val = num[i];
			temp = temp->next;
		}
		return head;
    }
};
