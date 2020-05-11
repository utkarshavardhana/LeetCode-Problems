// Problem: https://leetcode.com/problems/integer-to-roman/
//
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
// Input: 3
// Output: "III"
//
// Example 2:
// Input: 4
// Output: "IV"
//
// Example 3:
// Input: 9
// Output: "IX"
//
// Example 4:
// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
//
// Example 5:
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    string intToRoman(int num) {
        // map<int, char> m;
        // m[1]='I';
        // m[5]='V';
        // m[10]='X';
        // m[50]='L';
        // m[100]='C';
        // m[500]='D';
        // m[1000]='M';
        string str;
        int unit = 1;
        while(num){
            int now = num%10;
            string temp;
            if(unit==1){
                if(now==9){
                    temp.insert(temp.end(), 'I');
                    temp.insert(temp.end(), 'X');
                }else if(now>=5){
                    temp.insert(temp.end(), 'V');
                    now-=5;
                    while(now--){
                        temp.insert(temp.end(), 'I');
                    }
                }else{
                    if(now==4){
                        temp.insert(temp.end(), 'I');
                        temp.insert(temp.end(), 'V');
                    }else{
                        while(now--){
                            temp.insert(temp.end(), 'I');
                        }
                    }
                }
            }else if(unit==10){
                if(now==9){
                    temp.insert(temp.end(), 'X');
                    temp.insert(temp.end(), 'C');
                }else if(now>=5){
                    temp.insert(temp.end(), 'L');
                    now-=5;
                    while(now--){
                        temp.insert(temp.end(), 'X');
                    }
                }else{
                    if(now==4){
                        temp.insert(temp.end(), 'X');
                        temp.insert(temp.end(), 'L');
                    }else{
                        while(now--){
                            temp.insert(temp.end(), 'X');
                        }
                    }
                }
            }else if(unit==100){
                if(now==9){
                    temp.insert(temp.end(), 'C');
                    temp.insert(temp.end(), 'M');
                }else if(now>=5){
                    temp.insert(temp.end(), 'D');
                    now-=5;
                    while(now--){
                        temp.insert(temp.end(), 'C');
                    }
                }else{
                    if(now==4){
                        temp.insert(temp.end(), 'C');
                        temp.insert(temp.end(), 'D');
                    }else{
                        while(now--){
                            temp.insert(temp.end(), 'C');
                        }
                    }
                }
            }else{
                while(now--){
                    temp.insert(temp.end(), 'M');
                }
            }
            unit*=10;
            num/=10;
            for(int k=temp.size()-1; k>=0; k--){
                str.insert(str.begin(), temp[k]);
            }
        }
        return str;
    }
};
