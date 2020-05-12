// Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/
//
// Given a binary tree, return the postorder traversal of its nodes' values.
//
// Example:
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [3,2,1]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*> st;
        while(root) {
            st.push(root);
            root = root->left;
        }
        while(!st.empty()) {
            TreeNode* t = st.top();
            if(t->right) {
                TreeNode* r = t->right; 
                while(r) { 
                    st.push(r);
                    r = r->left;
                }
            } else {
                st.pop();
                res.push_back(t->val);
            }
            t->right = NULL;
        }
        return res;
    }
};
