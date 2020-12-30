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
    ListNode *detectCycle(ListNode *head) {
        while(head){
            if(head->val == INT_MAX) return head;
            head->val = INT_MAX;
            head = head->next;
        }
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) { // two pointers
        if(!head) return nullptr;
        ListNode* fast=head->next, *ptr = head;
        while(fast!=head){
            if(!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            head = head->next;
        }
        head=head->next;
        while(head!=ptr){
            head=head->next;
            ptr = ptr->next;
        }
        return ptr;
    }*/
    ListNode *detectCycle(ListNode *head) { // two pointers, a slight change
        ListNode* fast=head, *ptr = head;
        while(fast){
            head=head->next;
            if(!fast->next) return nullptr;
            fast = fast->next->next;
            if(fast==head){
                while(ptr!=head){
                    ptr=ptr->next;
                    head=head->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
