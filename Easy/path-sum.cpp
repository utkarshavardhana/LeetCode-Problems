// Problem: https://leetcode.com/problems/path-sum/
//
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    
    bool _hasPathSum(TreeNode* root, int sumTillNow, int sum) {
        if(!root)   return false;
        if(!root->left and !root->right) {
            sumTillNow += root->val;
            if(sumTillNow == sum)   return true;
            return false;
        }
        return _hasPathSum(root->left, sumTillNow+root->val, sum) 
            or _hasPathSum(root->right, sumTillNow+root->val, sum);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        return _hasPathSum(root, 0, sum);
    }
};
