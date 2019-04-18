#include<iostream>
#include<string>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        vector<int> table(128, 0);
        int left = 0, count = 0, length = INT_MAX;
        int tlen = t.length(), slen = s.length();
        for(int i = 0; i < tlen; ++i)
        {
        	++table[t[i]];
		}
		for(int i = 0; i < slen; ++i)
		{
			--table[s[i]];
			if(table[s[i]] >= 0)
			{
				++count;
			}
			while(count == tlen)
			{
				if(length > i - left + 1)
				{
					length = i - left + 1;
					result = s.substr(left, length);
				}
				++table[s[left]];
				if(table[s[left]] > 0)
				{
					--count;
				}
				++left;
			}
		}
		return result;
    }
};
