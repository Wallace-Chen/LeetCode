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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* start = new ListNode(), *end=head, *curr = start;
        start->next = head;
        while(end->next){
            ListNode *tmp = end->next;
            if(tmp->val > end->val) {end = end->next; continue;}
            //remove node from the list
            end->next = tmp->next;
            // insert node into list
            while(curr->next->val < tmp->val){
                curr = curr->next;
            }
            tmp->next = curr->next;
            curr->next = tmp;
            curr = start;
        }
        return start->next;
    }
};
