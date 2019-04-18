#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
	bool dfs(string s, unordered_set<string>& hash, int index, vector<int>& flag)
	{
		int length = s.length();
		if(index >= length)
		{
			return true;
		}
		else if(flag[index] != -1)
		{
			return flag[index];
		}
		for(int i = index+1; i <= length; ++i)
		{
			if(hash.count(s.substr(index, i - index)) == 1 && dfs(s, hash, i, flag))
			{
				flag[index] = 1;
				return true;
			}
		}
		flag[index] = 0;
		return false;
	}
	
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<int> flag(s.length(), -1);
        return dfs(s, hash, 0, flag);
    }
};
