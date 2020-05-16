// Problem: https://leetcode.com/problems/pascals-triangle/
//
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows == 0) {
            return res;
        }
        res.push_back({1});
        for(int i=1; i<numRows; i++) {
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++) {
                temp[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
