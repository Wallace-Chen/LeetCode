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
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) { //Morris method: very simliar to the inorder traversal
        TreeNode* curr = root, *pre;
        while(curr){
            pre = curr->left;
            if(pre){
                while(pre->right && pre->right!=curr) pre = pre->right; // get the predecessor of curr Node
                if(!pre->right){ // link
                    pre->right = curr;
                    ret.push_back(curr->val); // only difference with inorder tranversal, should be moved below
                    curr = curr->left;
                }else{ // encounter the visited node,need to remove the added link
                    pre->right = nullptr;
                    curr = curr->right;
                }
            }else {
                ret.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ret;
    }
    /*
    vector<int> preorderTraversal(TreeNode* root) { //iteratively
        stack<TreeNode*> stk;
        while(root||stk.size()>0) {
            while(root){
                stk.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return ret;
    }
    */
    /*
    vector<int> preorderTraversal(TreeNode* root) { //iteratively
        stack<TreeNode*> stk;
        while(root||stk.size()>0) {
            if(!root){
                root = stk.top();
                stk.pop();
            }
            ret.push_back(root->val);
            if(root->right) stk.push(root->right);
            root = root->left;
        }
        return ret;
    }
    */
    /*
    vector<int> preorderTraversal(TreeNode* root) { //resursively
        preorder(root);
        return ret;
    }
    
    void preorder(TreeNode* root){
        if(!root) return;
        ret.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }*/
};
