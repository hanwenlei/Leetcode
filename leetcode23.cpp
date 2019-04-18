#include<iostream>
#include<queue>
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

struct compare
{
	bool operator() (const ListNode* a, const ListNode* b)
	{
		if(a == NULL)
		{
			return true;
		}
		else if(b == NULL)
		{
			return false;
		}
		return a->val > b->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<ListNode*, vector<ListNode*>, compare> que;
    	int length = lists.size();
    	for(int i = 0; i < length; ++i)
    	{
    		que.push(lists[i]);
		}
		ListNode* root = new ListNode(0);
		ListNode* temp = root;
		while(!que.empty())
		{
			temp->next = que.top();
			temp = temp->next;
			if(temp == NULL)
			{
				break;
			}
			que.pop();
			if(temp->next != NULL)
			{
				que.push(temp->next);
			}
		}
		return root->next;
    }
};
