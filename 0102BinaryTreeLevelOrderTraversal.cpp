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
    // iteratively
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > out;
        levelOrder(root, 0, out);
        /*
        if(!root) return out;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            out.push_back(vector<int>());
            int s = q.size();
            for(int i=0;i < s;i++){
                auto curr = q.front(); q.pop();
                out[level].push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level ++;
        }
        */
        return out;
    }
    // recursively
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& out) {
        if(!root) return;
        if(out.size()<level+1) out.push_back(vector<int>());
        out[level].push_back(root->val);
        levelOrder(root->left, level+1, out);
        levelOrder(root->right, level+1, out);
    }
    
};
