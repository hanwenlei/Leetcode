#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(result, candidates, 0, temp, target);
        return result;
    }
    
    int dfs(vector<vector<int>>& result, vector<int>& candidates, int index, vector<int>& vec, int target)
    {
    	if(target == 0)
    	{
    		result.push_back(vec);
    		return 0;
		}
    	for(int it = index; it < candidates.size(); ++it, ++index)
    	{
    		if(target >= candidates[it])
    		{
    			vec.push_back(candidates[it]);
    			target -= candidates[it];
    			dfs(result, candidates, index, vec, target);
    			vec.pop_back();
    			target += candidates[it];
			}
		}
    	return 0;
	}
};
