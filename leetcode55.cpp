#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.size() == 1 || nums.size() == 0)
    	{
    		return true;
		}
    	vector<int>::iterator it = nums.begin();
        while(true)
        {
        	vector<int>::iterator temp = it;
        	bool flag = false;
        	it = find(temp, nums.end(), 0);
        	if(it == nums.end() || it == nums.end() - 1)
        	{
        		return true;
			}
			temp = it;
			for(int i = 0; temp >= nums.begin(); --temp, ++i)
			{
				if(*temp > i)
				{
					flag = true;
					break;
				}
			}
			if(flag == false)
			{
				return false;
			}
			temp = it;
			--temp;
			for(int i = *temp; i > 0; --i)
			{
				++temp;
			}
			if(temp == nums.end())
			{
				return true;
			}
			++it;
		}
    }
};
