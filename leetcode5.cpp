#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "!#";
        int length = s.length();
        for(int i = 0; i < length; ++i)
        {
        	temp += s[i];
        	temp += '#';
		}
		length = temp.length();
		int* p = new int[length];
		memset(p, 0, length*sizeof(int));
		int remx = 0, reid = 0, mx = 0, id = 0;
		
		for(int i = 0; i < length; ++i)
		{
			if(mx  > i)
			{
				p[i] = min(p[2*id - i], mx - i);
			}
			else
			{
				p[i] = 1;
			}
			while((i - p[i] >= 0) && (temp[i + p[i]] == temp[i - p[i]]))
			{
				++p[i];
			}
			if(mx < i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
			if(remx < p[i])
			{
				remx = p[i];
				reid = i;
			}
		}
		
		return s.substr((reid-remx)/2, remx-1);
    }
};
