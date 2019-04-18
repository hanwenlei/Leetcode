#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int length = strs.size();
        vector<vector<string>> result;
        map<string, vector<string>> tempmap;
        for(int i = 0; i < length; ++i)
        {
        	string temp = strs[i];
        	sort(temp.begin(), temp.end());
        	tempmap[temp].push_back(strs[i]);
		}
		for(auto it = tempmap.begin(); it != tempmap.end(); ++it)
		{
			result.push_back(it->second);
		}
		return result;
    }
};
