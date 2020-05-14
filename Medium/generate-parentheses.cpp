// Problem: https://leetcode.com/problems/generate-parentheses/
//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        generate(0,0,"",n);
        return ans;
    }
    void generate(int open,int closed, string k, int required) {
        if(k.length()==2*required) {
            ans.push_back(k);
        }
        else{
            if(open<required)
                generate(open+1,closed,k+"(",required);
            if(closed<open)
                generate(open,closed+1,k+")",required);
        }
        return;
    }
};
