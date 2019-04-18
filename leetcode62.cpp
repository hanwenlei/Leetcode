#include<iostream>
#include<cstring>

using namespace std;

int dp[100][100];

class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp, 0, 10000*sizeof(int));
        for(int i = 0; i < n; ++i)
        {
        	dp[i][0] = 1;
		}
        for(int i = 0; i < n; ++i)
        {
        	for(int j = 1; j < m; ++j)
        	{
        		if(i == 0)
        		{
        			dp[i][j] = dp[i][j-1];
				}
				else
				{
					dp[i][j] = dp[i][j-1] + dp[i-1][j];
				}
 			}
		}
		return dp[n-1][m-1];
    }
};
