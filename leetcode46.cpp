#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
    
    int dfs(vector<int>& nums, int index, vector<vector<int>>& result)
    {
    	int length = nums.size();
    	if(index == length-1)
    	{
    		result.push_back(nums);
    		return 0;
		}
		for(int i = index; i < length; ++i)
		{
			swap(nums[index], nums[i]);
			dfs(nums, index+1, result);
			swap(nums[index], nums[i]);
		}
    	return 0;
	}
};
