#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

class Solution {
public:	
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
        {
        	return intervals;
		}
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval>::iterator it1 = intervals.begin();
        vector<Interval>::iterator it2 = intervals.begin();
        ++it2;
        while(it2 != intervals.end())
        {
        	if((*it1).end >= (*it2).start)
        	{
        		(*it2).start = (*it1).start;
        		if((*it1).end > (*it2).end)
        		{
        			(*it2).end = (*it1).end;
				}
			}
			else
			{
				result.push_back(*it1);
			}
			++it1;
			++it2;
		}
		result.push_back(*it1);
		return result;
    }
};
