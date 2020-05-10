// Problem: https://leetcode.com/problems/reverse-integer/
// 
// Given a 32-bit signed integer, reverse digits of an integer.
// 
// Example 1:
// Input: 123
// Output: 321
// 
// Example 2:
// Input: -123
// Output: -321
// 
// Example 3:
// Input: 120
// Output: 21
// 
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-231,  231 - 1]. 
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        int neg = 0;
        if(x < 0)   neg++;
        x = abs(x);
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        long long res = 0;
        for(char c : str) {
            res *= 10;
            res += c - '0';
        }
        if(neg > 0)
            res  = -1*res;
        if(res < (-1 * pow(2, 31)) or (res > pow(2, 31) - 1) )  return 0;
        return res;
    }
};
