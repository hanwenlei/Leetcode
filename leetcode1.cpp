#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
    	int temp = 0;
    	vector<int> result(2);
        for(vector<int>::iterator it = nums.begin(); it < nums.end(); ++it)
        {
        	temp = target - (*it);
        	++it;
        	vector<int>::iterator i = it;
        	--it;
        	for(; i < nums.end(); ++i)
        	{
        		if(temp == (*i))
        		{
        			result[0] = it - nums.begin();
        			result[1] = i - nums.begin();
        			return result;
				}
			}
		}
		return result;
    }
};
