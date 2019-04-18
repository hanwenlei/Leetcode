#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < length; ++i)
		{
			vector<int> temp;
			int left = i + 1, right = length - 1;
			if(nums[i] > 0)
			{
				break;
			}
			int target = -nums[i];
			temp.push_back(nums[i]);
			while(left < right)
			{
				if(nums[left] + nums[right] == target)
				{
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					result.push_back(temp);
					temp.pop_back();
					temp.pop_back();
					++left;
					--right;
					while((right > 0) && (nums[right] == nums[right+1]))
					{
						--right;
					}
				}
				else if(nums[left] + nums[right] < target)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
			while((i+1 < length) && (nums[i] == nums[i+1]))
			{
				++i;
			}
		}
		return result;
    }
};
