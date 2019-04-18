#include<iostream>
#include<vector>

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
    bool isPalindrome(ListNode* head) {
        int number = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        vector<int> res1;
        vector<int> res2;
        if(head == NULL || head->next == NULL)
        {
        	return true;
		}
		while(temp1 != NULL)
		{
			temp1 = temp1->next;
			++number;
		}
		temp1 = head;
		if(number & 1)
		{
			number = number / 2 + 1;
		}
		else
		{
			number /= 2;
		}
		while(number--)
		{
			temp1 = temp1->next;
		}
		while(temp1 != NULL)
		{
			res1.push_back(temp1->val);
			res2.push_back(temp2->val);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		int length = res1.size();
		for(int i = 0; i < length; ++i)
		{
			if(res1[i] != res2[length - i - 1])
			{
				return false;
			}
		}
		return true;
    }
};
