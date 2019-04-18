#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1000;
int dp[MAX][MAX];

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	memset(dp, 0, MAX*MAX*sizeof(int));
        int hang = grid.size();
        int lie = grid[0].size();
        dp[0][0] = grid[0][0];
        for(int i = 1; i < hang; ++i)
        {
        	dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for(int i = 0; i < hang; ++i)
		{
			for(int j = 1; j < lie; ++j)
			{
				if(i == 0)
				{
					dp[i][j] = dp[i][j-1] + grid[i][j];
				}
				else
				{
					dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
				}
			}
		}
		return dp[hang-1][lie-1];
    }
};
