#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool dfs(vector<vector<char>>& board, string word, int x, int y, int index)
	{
		bool result = false;
		if(index == word.length())
		{
			return true;
		}
		else if(x < 0 || y < 0 || x >= board.size() || y >= board[x].size())
		{
			return false;
		}
		else if(board[x][y] != word[index])
		{
			return false;
		}
		else
		{
			char temp = board[x][y];
			board[x][y] = '0';
			++index;
			result = dfs(board,word,x-1,y,index) || dfs(board,word,x+1,y,index) || dfs(board,word,x,y-1,index) || dfs(board,word,x,y+1,index);
			board[x][y] = temp;
			return result;
		}
	}
	
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.length() == 0)
        {
        	return false;
		}
		for(int i = 0; i < board.size(); ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(dfs(board, word, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
    }
};
