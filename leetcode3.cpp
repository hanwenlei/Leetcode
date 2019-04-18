#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> index(256, -1);
		int length = s.length();
		int result = 0, temp = -1;
		for(int i = 0; i < length; ++i)
		{
			if(index[s[i]] > temp)
			{
				temp = index[s[i]];
			}
			index[s[i]] = i;
			result = max(result, i - temp);
		}
		return result;
	}
};
