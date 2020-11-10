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
/* 
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, int num) {
        if(!root) return 0;
        num = num * 10 + root->val;
        if(!root->left && !root->right){
            return num;
        }
        
        return sumNumbers(root->left, num) + sumNumbers(root->right, num);
    }
*/
    
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        if(!root) return ret;
        queue<TreeNode*> nodeq;
        queue<int> numq;
        nodeq.push(root);
        numq.push(root->val);
        while(!nodeq.empty()){
            TreeNode* node = nodeq.front();
            int num = numq.front();
            nodeq.pop();
            numq.pop();
            if(!node->left && !node->right){
                ret += num;
            }else{
                if(node->left){
                    nodeq.push(node->left);
                    numq.push(num*10+node->left->val);
                }
                if(node->right){
                    nodeq.push(node->right);
                    numq.push(num*10+node->right->val);
                }
            }
        }
        return ret;
        
    }
    
};
