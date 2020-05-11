// Problem: https://leetcode.com/problems/3sum-closest/
//
// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mnDiff = INT_MAX, sum = 0;
        for(int i=0; i<nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            int t;
            while(j < k) {
                t = (nums[i] + nums[j] + nums[k]);
                if(abs(t - target) < mnDiff) {
                    mnDiff = abs( t-target);
                    sum = t;
                }
                if(t == target)  return t;
                else if(t > target)   k--;
                else    j++;
            }
        }
        return sum;
    }
};
