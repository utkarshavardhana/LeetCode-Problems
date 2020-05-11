// Problem: https://leetcode.com/problems/3sum/
//
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){return result;}
        sort(nums.begin(),nums.end());
        int i,j,k;
        for(i = 0; i < nums.size() - 2; ++i){
            if(nums[i] > 0) return result;
            j = i + 1;
            k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) ++j;
                    while(j < k && nums[k] == nums[k - 1]) --k;
                    if(j == k) break;
                    ++j;
                    --k;
                }else if(sum > 0) --k;
                 else ++j;
            }
            while(i < nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return result;
    }
};
