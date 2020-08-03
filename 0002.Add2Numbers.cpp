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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p = l1, *q = l2;
        ListNode* head = new ListNode(), *rlt = head;
        while(p != nullptr || q != nullptr){
            int x = (p==nullptr) ? 0 : p->val;
            int y = (q==nullptr) ? 0 : q->val;
            int sum = x + y + carry;
            rlt->next = new ListNode();
            rlt = rlt->next;
            rlt->val = sum%10;
            carry = sum / 10;
            if(p != nullptr) p = p->next; 
            if(q != nullptr) q = q->next;
        }
        
        if(carry > 0) rlt->next = new ListNode(carry);
        
        return head->next;
    }
};