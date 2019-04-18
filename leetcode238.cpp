#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int result1 = 1, result2 = 1;
        int count = 0;
        int length = nums.size();
        vector<int> result(length, 0);
        for(int i = 0; i < length; ++i)
        {
        	if(nums[i] == 0)
        	{
        		result1 = 0;
        		++count;
			}
        	else
        	{
        		result1 *= nums[i];
        		result2 *= nums[i];
			}
		}
		for(int i = 0; i < length; ++i)
		{
			if(nums[i] == 0)
			{
				if(count == 1)
				{
					result[i] = result2;
				}
				else
				{
					result[i] = 0;
				}
			}
			else
			{
				result[i] = result1 / nums[i];
			}
		}
		return result;
    }
};
