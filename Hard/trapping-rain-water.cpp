// Problem: https://leetcode.com/problems/trapping-rain-water/
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
// Example:
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int> r,l;r=l=v;
        for(int i=1; i<n; i++)	r[i] = max(r[i-1], r[i]);
        for(int i=n-2; i>=0; i--)	l[i] = max(l[i+1], l[i]);
        int ans = 0;
        
        for(int i=0; i<n; i++){
            ans += (min(r[i], l[i]) - v[i]);
        }
        return ans;
    }
};
