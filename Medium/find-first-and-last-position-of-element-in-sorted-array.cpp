// Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// 
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;

        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<target){
                l=m+1;
            }else{
                r=m;
            }
        }

        int first=l;
        if(l<nums.size()&&nums[l]==target){//l is in boundary and is the target
            l=0;
            r=nums.size()-1;
            while(l<r){
                int m=l+(r-l+1)/2;
                if(nums[m]>target){
                    r=m-1;
                }else{
                    l=m;
                }
            }

            return vector<int> {first, r};
        }
        return vector<int> {-1, -1};
    }
};
