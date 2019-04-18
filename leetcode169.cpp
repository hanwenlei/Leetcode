#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hash;
		int length = nums.size();
		for(int i = 0; i < length; ++i)
		{
			++hash[nums[i]];
		}
		map<int, int>::iterator temp = hash.begin();
		for(map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it)
		{
			if(temp->second < it->second)
			{
				temp = it;
			}
		}
		return temp->first;
    }
};
