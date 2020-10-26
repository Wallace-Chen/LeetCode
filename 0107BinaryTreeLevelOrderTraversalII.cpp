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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> out;
        if(!root) return out;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            out.insert(out.begin(), vector<int>());
            int s = q.size();
            for(int i=0;i<s;i++){
                auto tmp = q.front(); q.pop();
                out[0].push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return out;
    }
};
