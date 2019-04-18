#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int result = INT_MIN;
        int temp1 = 1, temp2 = 1;
        for(int i = 0; i < length; ++i)
        {
        	temp1 *= nums[i];
        	temp2 *= nums[length-i-1];
        	result = max(result, max(temp1, temp2));
        	if(temp1 == 0)
        	{
        		temp1 = 1;
			}
			if(temp2 == 0)
			{
				temp2 = 1;
			}
		}
		return result;
    }
};
