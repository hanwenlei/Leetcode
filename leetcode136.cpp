#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> hash;
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
        	++hash[nums[i]];
		}
		map<int, int>::iterator it = find_if(hash.begin(), hash.end(), [] (const pair<int, int>& item) {
			return item.second == 1;
		});
		return it->first;
    }
};
