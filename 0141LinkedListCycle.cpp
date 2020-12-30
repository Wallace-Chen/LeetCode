/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    bool hasCycle(ListNode *head) {
        while(head){
            if(head->val == INT_MAX) return true;
            head->val = INT_MAX;
            head = head->next;
        }
        return false;
    }
    */
    bool hasCycle(ListNode *head) { // two pointers solution
        if(!head) return false;
        ListNode *fast = head->next;
        while(fast != head){
            if(!fast || !fast->next) return false;
            fast = fast->next->next;
            head = head->next;
        }
        return true;
        
    }
};
