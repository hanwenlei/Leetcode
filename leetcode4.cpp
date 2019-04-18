#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size();
    	int n = nums2.size();
        vector<int> a(m+n);
        if(m != 0)
        {
        	memcpy(a.data(), nums1.data(), sizeof(int)*m);
		}
		if(n != 0)
		{
			memcpy(a.data()+m, nums2.data(), sizeof(int)*n);
		}
        sort(a.begin(), a.end());
        if((m + n) % 2 == 0)
        {
        	return (double)(a[(m+n)/2] + a[(m+n)/2-1])/2;
		}
		else
		{
			return a[(m+n)/2];
		}
    }
};
