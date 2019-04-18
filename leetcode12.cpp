#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char ch[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int count[7] = {1000, 500, 100, 50, 10, 5, 1};
        int temp = 0;
        string result = "";
        for(int i = 0; i < 7; i = i + 2)
        {
        	temp = num / count[i];
        	if(temp > 0 && temp < 4)
        	{
        		for(int j = 0; j < temp; ++j)
        		{
        			result += ch[i];
				}
			}
			else if(temp == 4)
			{
				cout << 1 << endl;
				result = result + ch[i] + ch[i-1];
			}
			else if(temp == 5)
			{
				result += ch[i-1];
			}
			else if(temp > 5 && temp < 9)
			{
				result += ch[i-1];
				temp -= 5;
				for(int j = 0; j < temp; ++j)
        		{
        			result += ch[i];
				}
			}
			else if(temp == 9)
			{
				result = result + ch[i] + ch[i-2];
			}
			num %= count[i];
		}
		return result;
    }
};

int main(void)
{
	Solution s;
	cout << s.intToRoman(4) << endl;
}
