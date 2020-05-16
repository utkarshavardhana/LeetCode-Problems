// Problem: https://leetcode.com/problems/symmetric-tree/
//
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 
// But the following [1,2,2,null,3,null,3] is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
// Follow up: Solve it both recursively and iteratively.

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
    bool isSymmetric(TreeNode* root) {
        return root ? isSymmetric(root->left, root->right) : true;
    }
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(!l || !r || l->val != r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};
