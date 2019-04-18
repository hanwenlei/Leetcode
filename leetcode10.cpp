#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
        {
        	return s.empty();
		}
        if(p.length() == 1)
		{
			if(s.length() == 1)
			{
				if(s[0] == p[0] || p[0] == '.')
				{
					return true;
				}
				return false;
			}
			return false;
        }
        if(p[1] != '*')
		{
            if(s.empty())
            {
            	return false;
			}
			if(s[0] == p[0] || p[0] == '.')
			{
				return isMatch(s.substr(1), p.substr(1));
			}
            return false;
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
            if(isMatch(s, p.substr(2)))
			{
				return true;
			}
			else
			{
				s = s.substr(1);
			}
        }
        return isMatch(s, p.substr(2));
    }
};
