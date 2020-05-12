// Problem: https://leetcode.com/problems/valid-number/
//
// Validate if a given string can be interpreted as a decimal number.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false
//
// Note: It is intended for the problem statement to be ambiguous. 
// You should gather all requirements up front before implementing one. 
// However, here is a list of characters that can be in a valid decimal number:
//
// Numbers 0-9
// Exponent - "e"
// Positive/negative sign - "+"/"-"
// Decimal point - "."
// Of course, the context of these characters also matters in the input.

class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0) return false;
        int i = 0,n = s.length()-1;
        bool e = false, dot = false, digit = false;

        while(i < s.length() && s[i] == ' ') i++;  
        while(n>= 0 && s[n] == ' ') n--;

        if(s[i] == '+' || s[i] == '-') i++;
        if(i > n) return false;
        for(; i <= n; i++){
            if(isdigit(s[i])){
                digit = true;     // atleast one digit
                continue;
            }
            else if(s[i] == 'e' && digit && i != n && !e){ 
                e = true;
                if(s[i + 1] == '+' || s[i + 1] == '-')     
                    if(i == n - 1) return false;
                    else i++;
            }
            else if(s[i] == '.' && !dot && !e)  dot = true;     // atmost one dot
            else return false;
        }
        return digit;
    }
};
