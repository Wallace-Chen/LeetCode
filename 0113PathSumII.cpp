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
    vector<vector<int>> out = {};
    vector<int> path = {};
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return out;
    }
    
    void dfs(TreeNode* root, int sum) {
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum == root->val){
            out.push_back(path);
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        path.pop_back();
    }
};
