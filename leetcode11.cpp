#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> result;
        vector<int>::iterator itb = height.begin();
        vector<int>::iterator ite = height.end();
        --ite;
        int temp = 0;
        while(itb != ite)
        {
        	temp = (ite - itb)*min(*itb, *ite);
        	result.push_back(temp);
        	if(*itb <= *ite)
        	{
        		++itb;
			}
			else
			{
				--ite;
			}
		}
		return (*max_element(result.begin(), result.end()));
    }
};
