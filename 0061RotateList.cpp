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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        int len=0;
        ListNode* probe = head, *start;
        while(probe->next!=nullptr){
            probe = probe->next;
            len++;
        }
        if(k%(len+1)==0){
            return head;
        }
        probe->next = head;
        int offset = k%(len+1);
        probe = head;
        for(int i=0;i<(len)-offset;i++) probe = probe->next;
        start = probe->next;
        probe->next=nullptr;
        probe = start;
        return start;
    }
};