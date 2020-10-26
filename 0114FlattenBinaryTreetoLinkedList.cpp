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
    void flatten(TreeNode* root) { // Method 1: whenver find a left child, stack its right child and connect left child to the right link of the current node, when meet a node without any child then pop the right child from the stack and connect it to the right link of the current node
        TreeNode* head = root;
        stack<TreeNode*> stk;
        while(!stk.empty() || head){
            if(head->left){ // if find left child
                if(head->right) stk.push(head->right); //push right child to stack
                head->right = head->left; // cut left child and connect it to the right link
                head->left = nullptr;
            }else if(!head->left && !head->right){ // node has no child
                if( stk.empty() ) return; // no stacked nodes, all done
                head->right = stk.top(); // connect right link to the stacked node
                stk.pop();
            }
            head = head->right; // step right
        }
    }
    */
    /*
    void flatten(TreeNode* root) { // Method 2: based on Method 1, the observation is that the right child must be connected to right link of the predecessor of the current node, thus no need to use stack to store the right child anymore
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* left = curr->left, *predecessor = left;
                while(predecessor->right) predecessor=predecessor->right; // get the predecessor
                predecessor->right = curr->right;
                curr->right = left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
    */
    void flatten(TreeNode* root) { // Method 3: a recurisve method, assume the left sub-tree and right sub-tree have been flattened, then simply connect right sub-tree to the right link of the predecessor of the current node.
        if(!root || (!root->left && !root->right) ) return;
        flatten(root->left);
        flatten(root->right);
        //now left and right sub-trees have been flattened. Note the following nodes are of similar idea to that in the if statement in the Method 2.
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right) root = root->right; // get the predecessor
        root->right = right; // connect right sub-tree to the right link of the predecessor
    }
    
};
