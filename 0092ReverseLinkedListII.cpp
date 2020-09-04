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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode *hd, *pre, *curr = new ListNode(0), *probe;
        curr->next = head;
        int cnt = 0;
        while(cnt < m) { // move cur to the position m
            if(cnt == m-1) hd = curr;
            curr = curr->next;cnt++;
        }
        pre = curr; curr = curr->next;
        while(cnt < n){
            probe = curr->next;
            curr->next = pre;
            cnt++;
            pre = curr; curr = probe;
        }
        probe = hd->next;
        hd->next = pre;
        probe->next = curr;
        return m==1 ? pre : head;
    }
};

/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *real_head = new ListNode(0);
        real_head -> next = head;
        ListNode *p, *pre = real_head, *tmp;
        n -= m;
        while(--m) pre = pre -> next;
        p = pre -> next;
        
        // reverse n-m nodes
        while(n--){
            tmp = p -> next;
            p -> next = tmp -> next;
            tmp -> next = pre -> next;
            pre -> next = tmp;   
        }
        return real_head -> next;
    }
};
*/
