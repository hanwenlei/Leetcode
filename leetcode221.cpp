#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len1 = matrix.size();
        if(len1 == 0)
        {
        	return 0;
		}
		int len2 = matrix[0].size();
		if(len2 == 0)
		{
			return 0;
		}
		vector<vector<int>> dp(len1, vector<int>(len2));
		int result = 0;
		for(int i = 0; i < len1; ++i)
		{
			dp[i][0] = matrix[i][0] - '0';
			if(result == 0)
			{
				result = dp[i][0] ? 1 : 0;
			}
		}
		for(int i = 0; i < len2; ++i)
		{
			dp[0][i] = matrix[0][i] - '0';
			if(result == 0)
			{
				result = dp[0][i] ? 1 : 0;
			}
		}
		for(int i = 1; i < len1; ++i)
		{
			for(int j = 1; j < len2; ++j)
			{
				if(matrix[i][j] == '1')
				{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
					result = max(result, dp[i][j]);
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		return result*result;
    }
};
