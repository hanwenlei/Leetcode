#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        for(int i = length-1; i > 0; --i)
        {
        	if(nums[i-1] < nums[i])
        	{
        		sort(nums.begin()+i, nums.end());
        		for(int j = i; j < length; ++j)
        		{
        			if(nums[i-1] < nums[j])
        			{
        				swap(nums[i-1], nums[j]);
        				return;
					}
				}
			}
		}
		sort(nums.begin(), nums.end());
    }
};
