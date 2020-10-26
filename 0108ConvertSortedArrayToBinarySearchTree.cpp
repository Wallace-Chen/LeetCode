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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int stop) {
        if(start>stop) return nullptr;
        TreeNode* root = new TreeNode( nums[start + (stop-start)/2] );
        root->left = sortedArrayToBST(nums, start, start + (stop-start)/2 - 1);
        root->right = sortedArrayToBST(nums, start + (stop-start)/2 + 1, stop);
        return root;
    }
};
