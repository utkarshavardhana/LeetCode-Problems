// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
// Example:
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// 
// Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution {
public:
    
    void recur(string digits, unordered_map<char, string> m, 
               string temp, vector<string> &res, int n) {
        if(temp.size() == n) {
            res.push_back(temp);
            return;
        }
        for(int i=0; i<digits.size(); i++) {
            char x = digits[i];
            string s = m[x];
            digits.erase(i, 1);
            for(char chr : s) {
                recur(digits, m, temp+chr, res, n);
            }
            // digits.insert(digits.begin()+i, x);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res;
        if(digits.size() == 0)  return res;
        string temp;
        recur(digits, m, temp, res, digits.size());
        return res;
    }
};
