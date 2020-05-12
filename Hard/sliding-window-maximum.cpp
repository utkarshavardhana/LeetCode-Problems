// Problem: https://leetcode.com/problems/sliding-window-maximum/
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Follow up:
// Could you solve it in linear time?
//
// Example:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 
//
// Constraints:
//
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= nums.length

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        int n = nums.size();
        if(n==0 or k==0)    return res;
        if(k >= n) {
            res.push_back(*max_element(nums.begin(), nums.end()));
            return res;
        }
        for(int i=0; i<k; i++) {
            m[nums[i]]++;
        }
        res.push_back((*(m.rbegin())).first);
        for(int i=k; i<n; i++) {
            m[nums[i]]++;
            m[nums[i-k]]--;
            if(m[nums[i-k]] == 0)    m.erase(nums[i-k]);
            res.push_back((*(m.rbegin())).first);
        }
        return res;
    }
};
