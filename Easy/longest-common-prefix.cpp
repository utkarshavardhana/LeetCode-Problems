// Problem: https://leetcode.com/problems/longest-common-prefix/
//
// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"
// 
// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// 
// Note:
// All given inputs are in lowercase letters a-z.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = "";
        if(!strs.size())	return pre;
        pre = strs[0];
        int n = pre.size();
        for(string s : strs) {
            if(s.size() >= n) {
                for(int i = n-1; i >= 0; i--) {
                    if(pre[i] == s[i])	continue;
                    else	n = i;
                }
            } else {
                n = s.size();
                for(int i = n-1; i >= 0; i--) {
                    if(pre[i] == s[i])	continue;
                    else	n = i;
                }
            }
            if(n > 0)	pre = pre.substr(0, n);
            else	pre = "";
        }
        return pre;
    }
};
