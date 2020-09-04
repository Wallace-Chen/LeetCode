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
class Solution { // Moriss Transerval
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rlt={};
        TreeNode *pre, *curr;
        while(root){
            if(!root->left){
                rlt.push_back(root->val);
                root = root->right;
                continue; // continue here is also important to make sure root is checked everytime
            }
            curr = root->left;
            while(curr->right && curr->right != root) curr = curr->right;
            if(!curr->right){
                curr->right = root;
                root = root->left;
                continue; // continue here is important to 
            }
            rlt.push_back(root->val); // make sure these part code is for the loop case
            curr->right = nullptr; // restore
            root = root->right;
        }
        return rlt;
    }
};
/* // using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rlt={};
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            rlt.push_back(root->val);
            root = root->right;
        }
        return rlt;
    }
};
*/

/* //Recursive Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        static vector<int> rlt;
        if(root == nullptr) return rlt;
        inorderTraversal(root->left);
        rlt.push_back(root->val);
        inorderTraversal(root->right);
        return rlt;
    }
};
*/
