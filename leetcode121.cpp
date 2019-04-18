#include<iostream>
#include<vector>
#include<algorithm>
#include<climits> 

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = INT_MAX, length = prices.size();
        int profit = 0;
        for(int i = 0; i < length; ++i)
        {
        	if(prices[i] < price)
        	{
        		price = prices[i];
			}
			else if(prices[i] - price > profit)
			{
				profit = prices[i] - price;
			}
		}
		return profit;
    }
};
