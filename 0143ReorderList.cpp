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
class Solution {
public:
    /*
    void reorderList(ListNode* head) {
        int i=0, num=0;
        stack<ListNode*> stk;
        ListNode* curr = head;
        while(curr){
            stk.push(curr);
            curr = curr->next;
            i++;
        }
        if(i<=2) return;
        curr = head;
        while(num<i/2){
            ListNode* tmp = curr->next;
            curr->next = stk.top();
            stk.pop();
            curr->next->next = tmp;
            curr = tmp;
            num++;
        }
        curr->next = nullptr;
        return;
    }
    */
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
    
     void reorderList(ListNode* head) {
         if(!head) return;
        ListNode* slow=head, *fast=head;
         while(fast->next && fast->next->next){// locate the mid point
             slow = slow->next;
             fast = fast->next->next;
         }
         
         ListNode* tmp = slow;
         slow = slow->next;
         tmp->next = nullptr;
         ListNode* right = reverseList(slow); //reverse the right part of list
         
         while(head && right){
             ListNode* tmp = head->next;
             head->next = right;
             ListNode* tmp_r = right->next;
             right->next = tmp;
             head = tmp;
             right = tmp_r;
         }
         
     }
    
        
};
