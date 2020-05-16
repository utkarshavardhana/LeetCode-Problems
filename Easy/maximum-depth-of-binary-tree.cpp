// Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
//
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its depth = 3.

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
    
    void _maxdepth(TreeNode* node, int depth, int &mx) {
        if(!node)   return;
        if(depth > mx)  mx = depth;
        _maxdepth(node->left, depth+1, mx);
        _maxdepth(node->right, depth+1, mx);
    }
    
    int maxDepth(TreeNode* root) {
        int mx = 0;
        if(!root)   return mx;
        _maxdepth(root, 1, mx);
        return mx;
    }
};
