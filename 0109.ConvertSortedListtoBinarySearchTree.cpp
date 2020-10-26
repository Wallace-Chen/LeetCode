/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) { // Method 1: recursion method, user fast and slow pointers to locate the middle element
        if(head == nullptr) return nullptr;
        ListNode *prev_ptr = head, *fast_ptr = head, *slow_ptr = head;
        while(fast_ptr->next != nullptr){
            fast_ptr = fast_ptr->next;
            if(fast_ptr->next == nullptr) break;
            fast_ptr = fast_ptr->next; 
            prev_ptr = slow_ptr; slow_ptr = slow_ptr->next;
        }
        TreeNode *root = new TreeNode(slow_ptr->val);
        root->right = sortedListToBST(slow_ptr->next);
        prev_ptr->next = nullptr;
        if(slow_ptr == head) root->left = nullptr;
        else
            root->left = sortedListToBST(head);
        return root;
    }
*/
    // Method 2: convert list to array, decrease the time complexity to O(N), while space complexity increased to O(lg(N)) , skipped
    
    // Method 3: mimic the inorder transverse and create the node from the head of linked list one by one
    ListNode *root = nullptr;
    
    TreeNode* sortedListToBST(ListNode* head) {
        root = head;
        int len = 0;
        while(head!=nullptr) {len++;head=head->next;}
        return sortedListToBST(0, len-1);
    }
    
    TreeNode* sortedListToBST(int start, int end) {
        if(start>end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *left = sortedListToBST(start, mid-1);
        
        TreeNode *node = new TreeNode(root->val);
        root = root->next;
        
        TreeNode *right = sortedListToBST(mid+1, end);
        node->left = left; node->right = right;
        
        return node;
    }
};
