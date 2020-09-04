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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p or !q ) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
/*
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<float> arr;
        preorder(p, arr, true);
        return preorder(q, arr, false);
    }
    bool preorder(TreeNode *root, vector<float> &arr, bool scan){
        if(root==nullptr){
            if(scan) arr.push_back(NAN);
            else if(arr.size()==0 || !isnan(arr[0])) return false;
            else arr.erase(arr.begin());
            return true;
        }
        if(scan) arr.push_back(root->val);
        else if(arr.size()==0 || arr[0]!=root->val) return false;
        else arr.erase(arr.begin());
        bool issame_left = preorder(root->left, arr, scan);
        if(!scan && !issame_left) return false;
        bool issame_right = preorder(root->right, arr, scan);
        if(!scan && !issame_right) return false;
        return true;
    }
};
*/
