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
    void addPath(TreeNode* root){
        int cnt=0;
        while(root){
            ret.push_back(root->val);
            root = root->right;
            cnt++;
        }
        reverse(ret.end()-cnt, ret.end());
    }
    vector<int> postorderTraversal(TreeNode* root) { // Morris method
        TreeNode *curr = root, *pre=nullptr;
        while(curr){
            pre = curr->left;
            if(pre){
                while(pre->right && pre->right!=curr) pre = pre->right;
                if(!pre->right){
                    pre->right = curr;
                    curr = curr->left;
                }else{
                    pre->right = nullptr;
                    addPath(curr->left);
                    curr = curr->right;
                }
            }else curr = curr->right;
        }
        addPath(root);
        return ret;
    }
    /*
    vector<int> postorderTraversal(TreeNode* root) { // "preorder" + output reverse
        stack<TreeNode*> stk;
        TreeNode* pre=nullptr;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                ret.push_back(root->val);
                root = root->right;
            }
            root = stk.top();
            stk.pop();
            root = root->left;
            
        }
        return vector(ret.rbegin(), ret.rend());
    }
    */
    /*
    vector<int> postorderTraversal(TreeNode* root) { // iteratively
        stack<TreeNode*> stk;
        TreeNode* pre=nullptr;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            if(root->right && root->right!=pre) root = root->right;
            else{
                stk.pop();
                ret.push_back(root->val);
                pre = root;
                root = nullptr;
            }
        }
        return ret;
    }
    */
    /*
    vector<int> postorderTraversal(TreeNode* root) { // recursively
        postorder(root);
        return ret;
    }
    
    void postorder(TreeNode* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        ret.push_back(root->val);
    }
    */
};
