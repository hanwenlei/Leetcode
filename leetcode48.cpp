#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        int length = matrix[0].size();
        for(int i = 0; i < length; ++i)
        {
        	vector<int> temp;
        	for(int j = length-1; j >= 0; --j)
        	{
        		temp.push_back(matrix[j][i]);
			}
			result.push_back(temp);
		}
		swap(matrix, result);
    }
};
