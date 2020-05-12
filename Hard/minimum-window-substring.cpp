// Problem: https://leetcode.com/problems/minimum-window-substring/
//
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
//
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minStart = left, minLen = INT_MAX;
        int remain = t.length();
        
        unordered_map<char, int> window;
        for (char c : t) {
            if (window.find(c) == window.end())
                window[c] = 1;
            else window[c] += 1;
        }
        
        for(; right < s.length(); right++) {
            char c = s.at(right);
            
            if(window.find(c) != window.end()) {
                window[c] -= 1;
                if (window[c] >= 0) remain--;
            }
                        
            while(remain == 0 && left <= right) {
                if(right-left+1 < minLen) {
                    minLen = right-left+1;
                    minStart = left;
                }
            
                //shrink
                char leftC = s.at(left);
                if(window.find(leftC) != window.end()) {
                    window[leftC] += 1;
                    if(window[leftC] >= 1) remain++;
                }
                left++;
            }
        }
        
        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};
