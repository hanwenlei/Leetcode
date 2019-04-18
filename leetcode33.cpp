#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int temp = find(nums.begin(), nums.end(), target) - nums.begin();
    	if(temp >= nums.size())
    	{
    		return -1;
		}
        return temp;
    }
};
