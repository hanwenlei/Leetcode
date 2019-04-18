#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int length = prerequisites.size();
		vector<vector<int>> graph(numCourses, vector<int>(0));
		vector<int> in(numCourses, 0);
		queue<int> que;
		pair<int, int> it;
		for(int i = 0; i < length; ++i)
		{
			it = prerequisites[i];
			graph[it.second].push_back(it.first);
			++in[it.first];
		}
		for(int i = 0; i < numCourses; ++i)
		{
			if(in[i] == 0)
			{
				que.push(i);
			}
		}
		int tmp = 0;
		while(!que.empty())
		{
			tmp = que.front();
			que.pop();
			for(int i = 0; i < graph[tmp].size(); ++i)
			{
				--in[graph[tmp][i]];
				if(in[graph[tmp][i]] == 0)
				{
					que.push(graph[tmp][i]);
				}
			}
		}
		vector<int>::iterator temp = find_if(in.begin(), in.end(), [] (const int i){
			return i != 0;
		});
		if(temp != in.end())
		{
			return false;
		}
		return true;
    }
};
