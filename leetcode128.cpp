#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        {
        	return 0;
		}
		sort(nums.begin(), nums.end());
        vector<int> temp(length, 1);
        for(int i = 1; i < length; ++i)
        {
        	if(nums[i] == nums[i-1] + 1)
        	{
        		temp[i] = temp[i-1] + 1;
			}
			else if(nums[i] == nums[i-1])
			{
				temp[i] = temp[i-1];
			}
		}
		return *(max_element(temp.begin(), temp.end()));
    }
};
