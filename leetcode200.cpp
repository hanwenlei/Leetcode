#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int dfs(vector<vector<char>>& grid, vector<vector<int>>& visit, int x, int y, int len1, int len2)
	{
		if(grid[x][y] == '0')
		{
			return 0;
		}
		else if(visit[x][y] == 1)
		{
			return 0;
		}
		
		visit[x][y] = 1;
		if(x > 0)
		{
			dfs(grid, visit, x-1, y, len1, len2);
		}
		if(y > 0)
		{
			dfs(grid, visit, x, y-1, len1, len2);
		}
		if(x+1 < len1)
		{
			dfs(grid, visit, x+1, y, len1, len2);
		}
		if(y+1 < len2)
		{
			dfs(grid, visit, x, y+1, len1, len2);
		}
		return 1;
	}
	
    int numIslands(vector<vector<char>>& grid) {
        int len1 = grid.size();
        if(len1 == 0)
        {
        	return 0;
		}
		int len2 = grid[0].size();
		int result = 0;
		vector<vector<int>> visit(len1, vector<int>(len2));
		for(int i = 0; i < len1; ++i)
		{
			for(int j = 0; j < len2; ++j)
			{
				result += dfs(grid, visit, i, j, len1, len2);
			}
		}
		return result;
    }
};
