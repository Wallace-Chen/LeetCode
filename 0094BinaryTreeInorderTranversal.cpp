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
	vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root, *pre;
        while(curr){
            pre = curr->left;
            if(pre){
                while(pre->right && pre->right!=curr) pre = pre->right; // get the predecessor of curr Node
                if(!pre->right){ // link
                    pre->right = curr;
                    curr = curr->left;
                }else{ // encounter the visited node,need to remove the added link
                    ret.push_back(curr->val); // only difference with the preorder, should be moved above
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
