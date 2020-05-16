// Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
// return its minimum depth = 2.

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
    
  int minDepth(TreeNode* root) {
      if(root==NULL)
          return 0;

      if(root->left==NULL&&root->right==NULL)
          return 1;

      if(root->left!=NULL&&root->right!=NULL)  
      return 1+min(minDepth(root->left),minDepth(root->right));
      else if(root->left!=NULL)
      return 1+minDepth(root->left);
      else
      return 1+minDepth(root->right);
    }
};
