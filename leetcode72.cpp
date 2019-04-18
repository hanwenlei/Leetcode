#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int dfs(string word1, int i, string word2, int j, vector<vector<int>>& temp)
	{
		int result = 0;
		int len1 = word1.length();
		int len2 = word2.length();
		if(i == len1)
		{
			return len2 - j;
		}
		else if(j == len2)
		{
			return len1 - i;
		}
		else if(temp[i][j] > 0)
		{
			return temp[i][j];
		}
		
		if(word1[i] == word2[j])
		{
			return dfs(word1, i+1, word2, j+1, temp);
		}
		else
		{
			int insnum = dfs(word1, i, word2, j+1, temp);
			int delnum = dfs(word1, i+1, word2, j, temp);
			int repnum = dfs(word1, i+1, word2, j+1, temp);
			result = min(insnum, min(delnum, repnum)) + 1;
		}
		temp[i][j] = result;
		return result;
	}

    int minDistance(string word1, string word2) {
    	int len1 = word1.length();
    	int len2 = word2.length();
    	vector<vector<int>> temp(len1, vector<int>(len2));
        return dfs(word1, 0, word2, 0, temp);
    }
};
