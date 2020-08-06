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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0 || head==NULL) return head;
        ListNode *p_del = new ListNode(), *curr = head;
        int pos = 0;
        while(curr->next != nullptr){
            pos ++;
            if(p_del->next != nullptr) p_del = p_del->next;
            if(pos == n) p_del = head;
            curr = curr->next;
        }
        if(p_del->next == nullptr) return head->next;
        p_del->next =  p_del->next->next;
        return head;
    }
};