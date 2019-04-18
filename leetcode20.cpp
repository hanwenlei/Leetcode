#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
        {
        	return true;
		}
		stack<char> temp;
		int length = s.length();
		for(int i = 0; i < length; ++i)
		{
			if(s[i] == ')')
			{
				if(!temp.empty() && temp.top() == '(')
				{
					temp.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
			if(s[i] == ']')
			{
				if(!temp.empty() && temp.top() == '[')
				{
					temp.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
			if(s[i] == '}')
			{
				if(!temp.empty() && temp.top() == '{')
				{
					temp.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
			temp.push(s[i]);
		}
		return temp.empty();
    }
};
