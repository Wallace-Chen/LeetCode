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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        TreeNode* tree = growTree(preorder, inorder, 0, preorder.size()-1, 0, mp);
        return tree;
    }
    
    TreeNode* growTree(vector<int>& preorder, vector<int>& inorder, int left, int right, int now, unordered_map<int, int>& mp){
        if(right<left) return nullptr;
        TreeNode* curr = new TreeNode(preorder[now]);
        int mid = mp[preorder[now]];
        curr->left = growTree(preorder, inorder, left, mid-1, now+1, mp);
        curr->right = growTree(preorder, inorder, mid+1, right, now+(mid-left)+1, mp);
        return curr;
    }
};
