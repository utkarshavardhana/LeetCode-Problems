// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
//
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

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
    
    void _levelOrderBottom(TreeNode* root, queue<TreeNode*> temp, vector<vector<int> > &res) {
        if(temp.empty())    return;
        queue<TreeNode*> q;
        vector<int> v;
        while(!temp.empty()) {
            TreeNode* node = temp.front();
            v.push_back(node->val);
            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
            temp.pop();
        }
        res.push_back(v);
        _levelOrderBottom(root, q, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> temp;
        if(root)    temp.push(root);
        _levelOrderBottom(root, temp, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
