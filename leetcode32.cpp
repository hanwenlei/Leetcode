#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.length();
        int result = 0, start = 0;
        stack<int> ss;
        for(int i = 0; i < length; ++i)
        {
        	if(s[i] == '(')
        	{
        		ss.push(i);
			}
			else
			{
				if(ss.empty())
				{
					start = i + 1;
				}
				else
				{
					ss.pop();
					if(ss.empty())
					{
						result = max(result, i - start + 1);
					}
					else
					{
						result = max(result, i - ss.top());
					}
				}
			}
		}
		return result;
    }
};
