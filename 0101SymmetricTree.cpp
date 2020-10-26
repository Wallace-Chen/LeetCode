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
    bool isSymmetric(TreeNode* root) {
        //return isSymmetric(root, root);
        return isSymmetric_it(root);
    }

    /*
// recursively
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left||!right) return false;
        if(left->val!=right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    */
// iteratively
    bool isSymmetric_it(TreeNode* root){
        stack<TreeNode*> stk;
        stk.push(root);
        stk.push(root);
        while(!stk.empty()){
            auto left = stk.top(); stk.pop();
            auto right = stk.top(); stk.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            stk.push(left->left); stk.push(right->right);
            stk.push(left->right); stk.push(right->left);
        }
        return true;
    }
};
