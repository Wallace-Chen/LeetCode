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
    bool isValidBST(TreeNode* root) {
        long tmp = LONG_MIN;
        return isValidBST(root, tmp);
    }
    bool isValidBST(TreeNode* root, long& num) {
        if(root==nullptr) {return true;}
        if(!isValidBST(root->left, num)) return false;
        if(root->val>num) num = root->val;
        else return false;
        if(!isValidBST(root->right, num)) return false;
        return true;
    }
};
