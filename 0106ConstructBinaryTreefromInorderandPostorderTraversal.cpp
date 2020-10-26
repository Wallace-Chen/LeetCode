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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        reverse(postorder.begin(), postorder.end());
        return growTree(postorder, inorder, 0, inorder.size()-1, 0, mp);
    }
    
    TreeNode* growTree(vector<int>& postorder, vector<int>& inorder, int left, int right, int now, unordered_map<int, int>& mp){
        if(right<left) return nullptr;
        TreeNode* curr = new TreeNode(postorder[now]);
        int mid = mp[postorder[now]];
        curr->left = growTree(postorder, inorder, left, mid-1, now+(right-mid)+1, mp);
        curr->right = growTree(postorder, inorder,mid+1, right, now+1, mp);
        return curr;
    }
};
