#include<iostream>
#include<vector>
#include<string>

using namespace std;

string s[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> re;

class Solution {
public:
	int findsolution(string digits, int index, string result)
	{
		int num = digits[index] - '0';
		string str = s[num-2];
		int i = str.length();
		for(int j = 0; j < i; ++j)
		{
			result += str[j];
			if(index+1 >= digits.length())
			{
				re.push_back(result);
			}
			else
			{
				findsolution(digits, index+1, result);
			}
			result.pop_back();
		}
		return 0;
	}
	
    vector<string> letterCombinations(string digits) {
        string result = "";
        re.clear();
        if(digits.size() != 0)
        {
        	findsolution(digits, 0, result);
		}
		return re;
    }
};
