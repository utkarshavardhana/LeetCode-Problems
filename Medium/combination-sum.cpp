// Problem: https://leetcode.com/problems/combination-sum/
//
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

class Solution {
public:
    
    void helperfunction(vector<vector<int>> &v,vector<int> chosen,vector<int> &can,int target,int index){
        if(target<0)
            return;
        if(target==0){
            v.push_back(chosen);
            return;
        }
        for(int i=index;i<can.size();i++){
            chosen.push_back(can[i]);
            helperfunction(v,chosen,can,target-can[i],i);
            chosen.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;vector<int> chosen;vector<vector<int>> v2;
        helperfunction(v,chosen,candidates,target,0);
        for(auto it: v){
            v2.push_back(it);
        }
        return v2;
    }
};
