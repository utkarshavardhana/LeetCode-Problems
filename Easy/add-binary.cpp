// Problem: https://leetcode.com/problems/add-binary/
//
// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
// 
//
// Constraints:
//
// Each string consists only of '0' or '1' characters.
// 1 <= a.length, b.length <= 10^4
// Each string is either "0" or doesn't contain any leading zero.

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0;
        int carry = 0;
        while(i<a.size()) {
            int t = a[i] + b[i] - 2*'0' + carry;
            if(t == 2) {
                b[i] = '0';
                carry = 1;
            } else if(t == 3) {
                b[i] = '1';
                carry = 1;
            } else {
                b[i] = '0' + t;
                carry = 0;
            }
            i++;
        }
        while(i<b.size()) {
            int t = b[i] - '0' + carry;
            if(t == 2) {
                b[i] = '0';
                carry = 1;
            } else {
                b[i] = '0' + t;
                carry = 0;
            }
            i++;
        }
        reverse(b.begin(), b.end());
        if(carry){
            b.insert(b.begin(), '0' + carry);
        }
        return b;
    }    
};
