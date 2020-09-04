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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(0), *l2 = new ListNode(0), *probe=head;
        ListNode *head_l1 = l1, *head_l2 = l2;
        while(head){
            if(head->val < x) {l1->next = head; l1 = l1->next;}
            else {l2->next = head; l2 = l2->next;}
            head = head->next;
        }
        l2->next = nullptr;
        l1->next = head_l2->next;
        return head_l1->next;
    }
};
