#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int result = 0, temp1 = 0, temp2 = 0;
        for(int i = 0; i < s.length(); ++i)
        {
        	if(i+1 == s.length())
        	{
        		result += (m.find(s[i]))->second;
        		break;
			}
        	temp1 = (m.find(s[i]))->second;
        	temp2 = (m.find(s[i+1]))->second;
        	if(temp1 < temp2)
        	{
        		result = result + temp2 - temp1;
        		++i;
			}
			else
			{
				result += temp1;
			}
		}
		return result;
    }
};
