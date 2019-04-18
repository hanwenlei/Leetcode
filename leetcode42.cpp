#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int result = 0, temp = 0;
        while(left+1 < right)
        {
        	if(height[left] < height[right])
        	{
        		temp = left + 1;
        		while(height[temp] < height[left])
        		{
        			result += height[left] - height[temp];
        			++temp;
				}
				left = temp;
			}
			else
			{
				temp = right - 1;
				while(height[temp] < height[right])
        		{
        			result += height[right] - height[temp];
        			--temp;
				}
				right = temp;
			}
		}
		return result;
    }
};
