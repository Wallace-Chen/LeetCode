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
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL)
            return l1==NULL ? l2 : l1;
        
        ListNode* head=(l1->val<l2->val) ? l1 : l2;
        head->next=mergeTwoLists(head==l1 ? l1->next : l1, head==l2 ? l2->next :l2);
        return head;
    }
};