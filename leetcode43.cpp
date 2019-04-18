#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        int m = num1.length(), n = num2.length();
        vector<int> count(m + n);
        int index = 0, temp = 0;
        for(int i = m - 1; i >= 0; --i)
        {
        	for(int j = n - 1; j >= 0; --j)
        	{
        		temp = (num1[i] - '0') * (num2[j] - '0');
        		index = i + j;
        		temp += count[index+1];
        		count[index+1] = temp % 10;
        		count[index] += temp / 10;
			}
		}
		for(int i = 0; i < m+n; ++i)
		{
			if((result.length() != 0) || (count[i] != 0))
			{
				result += count[i] + '0';
			}
		}
		if(result.length() == 0)
		{
			return "0";
		}
		else
		{
			return result;
		}
    }
};
