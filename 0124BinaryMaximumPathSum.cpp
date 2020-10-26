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
    int ret=INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ret;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        
        int left = max(0,helper(root->left)), right = max(0, helper(root->right));
        
        ret = max(ret, root->val + left + right);
        
        return root->val + max(left, right);
    }
};

