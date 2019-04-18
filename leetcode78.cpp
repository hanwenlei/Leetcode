#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1);
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
        	int size = result.size();
        	for(int j = 0; j < size; ++j)
        	{
        		result.push_back(result[j]);
        		result.back().push_back(nums[i]);
			}
		}
		return result;
    }
};
