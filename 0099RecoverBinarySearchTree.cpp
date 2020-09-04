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
    void recoverTree(TreeNode* root) {
        TreeNode *x=nullptr, *y=nullptr, *prev=nullptr;
        helper(root, &prev, &x, &y);
        swap(x->val, y->val);
    }
    
    void helper(TreeNode* root, TreeNode** prev, TreeNode** x, TreeNode** y) {
        if(root==nullptr) return;
        helper(root->left, prev, x, y);
        if((*prev)!=nullptr && root->val < (*prev)->val){
            (*x)=root;
            if((*y)==nullptr) *y=*prev;
            else return;
        }
        (*prev) = root;
        helper(root->right, prev, x, y);
    }
};
