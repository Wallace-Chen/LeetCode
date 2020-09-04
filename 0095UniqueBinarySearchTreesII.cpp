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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return *generateTrees(1, n);
    }
    
    vector<TreeNode*>* generateTrees(int from, int to) {
        vector<TreeNode*> *ret = new vector<TreeNode*>();
        if(to < from) ret->push_back(nullptr);
        else if (to == from) ret->push_back(new TreeNode(to));
        else 
            {for(int node=from;node<=to;node++){
            vector<TreeNode*> *left = generateTrees(from, node-1);
            vector<TreeNode*> *right = generateTrees(node+1, to);
            for(auto l:*left){
                for(auto r:*right){
                    TreeNode *root = new TreeNode(node);
                    root->left = l;
                    root->right = r;
                    ret->push_back(root);
                }
            }
            }
        }
        return ret;
    }
};
