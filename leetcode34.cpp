#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int temp = find(nums.begin(), nums.end(), target) - nums.begin();
        int length = nums.size();
        if(temp >= length)
        {
        	return result;
		}
		result[0] = temp;
		++temp;
		while(temp < length && nums[temp] == target)
		{
			++temp;
		}
		result[1] = temp-1;
		return result;
    }
};
