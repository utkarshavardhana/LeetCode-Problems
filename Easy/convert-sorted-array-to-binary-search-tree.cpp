// Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return NULL;
        TreeNode* node = new TreeNode(nums[n/2]);
        vector<int> left(nums.begin(), nums.begin()+n/2), right(nums.begin()+n/2+1, nums.end());
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};
