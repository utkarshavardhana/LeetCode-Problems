// Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        if(n == 0)	return 0;
        int cl=1, ml=1;
        int pi;
        vector<int> visited(256, -1);
        visited[s[0]] = 0;
        for(int i=1; i<n; i++){
            pi = visited[s[i]]; 
            if(pi == -1 || i-cl > pi) 
                cl++; 
            else{ 
                if (cl > ml)	ml = cl; 
                cl = i - pi; 
            } 
            visited[s[i]] = i; 
        }
        if (cl > ml)	ml = cl; 
        return ml; 
    }
};
