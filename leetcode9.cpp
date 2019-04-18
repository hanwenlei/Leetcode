#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long int temp = 0;
        int num = x;
        if(x < 0)
        {
        	return false;
		}
        while(num)
        {
        	temp = temp*10 + num%10;
        	num /= 10;
		}
		if(temp == x)
		{
			return true;
		}
		else
		{
			return false;
		}
    }
};
