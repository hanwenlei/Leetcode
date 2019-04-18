#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int length = nums.size();
    	if(length == 0)
    	{
    		return 0;
		}
		else if(length == 1)
		{
			return nums[0];
		}
		else if(length == 2)
		{
			return max(nums[0], nums[1]);
		}
        int* dp = new int[length];
        memcpy(dp, nums.data(), sizeof(int)*length);
        for(int i = 2; i < length; ++i)
        {
        	dp[i] += *max_element(dp, dp+i-1);
		}
		return max(dp[length-2], dp[length-1]);
    }
};
