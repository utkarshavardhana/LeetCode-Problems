// Problem: https://leetcode.com/problems/word-break-ii/
//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
//
// Example 1:
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
// Example 2:
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
// Example 3:
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

class Solution {
public:
    vector<string> wordBreak(string& s, int idx, unordered_set<string>& words, unordered_map<int, vector<string>>& dp) {
        if (dp.count(idx) == 0) {
            for (int i = idx-1; i >= 0; i--) {
                string tail = s.substr(i, idx-i);
                if (words.count(tail) == 0) continue;
                for (string sol : wordBreak(s, i, words, dp)) {
                    dp[idx].push_back(sol.append(tail).append(" "));
                }
            }
        }
        
        return dp[idx];
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.cbegin(), wordDict.cend());
        unordered_map<int, vector<string>> dp;
        dp[0] = {""};

        vector<string> result = wordBreak(s, s.length(), words, dp);
        for (string& sentence : result) sentence.pop_back();
        return result;
    }
};
