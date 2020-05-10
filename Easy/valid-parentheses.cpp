// Problem: https://leetcode.com/problems/valid-parentheses/
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
// Input: "()"
// Output: true
//  
// Example 2:
// Input: "()[]{}"
// Output: true
// 
// Example 3:
// Input: "(]"
// Output: false
// 
// Example 4:
// Input: "([)]"
// Output: false
// 
// Example 5:
// Input: "{[]}"
// Output: true

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' or c == '{' or c == '[') {
                st.push(c);
            } else {
                if(st.empty()) {
                    return false;
                }
                if(c == ')') {
                    if(st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if(c == '}') {
                    if(st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    if(st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};
