// Problem: https://leetcode.com/problems/4sum/
//
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

class Solution {
public:
    
    void kSum(vector<int> nums, int k, int target, int st, 
		      vector<int> temp, set<vector<int>> &res) {
        if(nums.size() - st < k) return;
        if(k == 2) {
            int lo = st, hi = nums.size()-1;
            while(lo < hi) {
                if(nums[lo] + nums[hi] == target) {
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.insert(temp);
                    temp.pop_back();
                    temp.pop_back();
                    lo++;
                    hi--;
                } else if(nums[lo] + nums[hi] < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        } else {
            for(int i=st; i<nums.size(); i++) {
                temp.push_back(nums[i]);
                kSum(nums, k-1, target-nums[i], st+(i-st+1), temp, res);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int k = 4;
        set<vector<int>> res;
        vector<vector<int>> ret;
        if(nums.empty() or nums.size() < 4)    return ret;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        kSum(nums, k, target, 0, temp, res);
        for(auto v : res)   ret.push_back(v);
        return ret;
    }
};
