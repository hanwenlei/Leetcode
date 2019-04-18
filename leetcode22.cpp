#include<iostream>
#include<string>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(n, n, "", result);
        return result;
    }
    
    int dfs(int ln, int rn, string s, vector<string>& result)
    {
    	if(ln > rn)
    	{
    		return 0;
		}
		if(ln == 0 && rn == 0)
		{
			result.push_back(s);
		}
		if(ln > 0)
		{
			dfs(ln-1, rn, s+'(', result);
		}
		if(rn > 0)
		{
			dfs(ln, rn-1, s+')', result);
		}
		return 0;
	}
};
