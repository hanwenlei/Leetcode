#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length);
        memcpy(dp.data(), nums.data(), length*sizeof(int));
        for(int i = 1; i < length; ++i)
        {
        	dp[i] = max(dp[i-1]+nums[i], dp[i]);
		}
		return *max_element(dp.begin(), dp.end());
    }
};
