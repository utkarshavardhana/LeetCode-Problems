// Problem: https://leetcode.com/problems/longest-palindromic-substring/
//
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)    return "";
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string res (1, s[0]);
        for(int len=0; len<n; len++) {
            for(int begin=0; begin<n-len; begin++) {
                int end = begin + len;
                if(begin == end) {
                    dp[begin][end] = 1;
                } else if(s[begin] == s[end] && dp[begin+1][end-1] == len - 1) {
                    dp[begin][end] = dp[begin+1][end-1] + 2;
                } else {
                    dp[begin][end] = 0;
                }
                if(dp[begin][end] > res.size()) {
                    res =  s.substr(begin, len+1);
                }
            }
        }
        return res;
    }
};
