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
    bool isBalanced(TreeNode* root) {
        bool isb=true;
        heights(root, isb);
        return isb;
    }
    
    int heights(TreeNode* root, bool& isb){
        if(!isb || root==nullptr) return 0;
        if(!root->left && !root->right) return 1;
        int left_h = heights(root->left, isb), right_h = heights(root->right, isb);
        if(abs(left_h-right_h)>1) isb=false;
        return max(left_h, right_h) + 1;
    }
};
