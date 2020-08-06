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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *probe = head, *delayed=head, *conn = new ListNode(), *first = new ListNode();
        int count = 0;
        while(probe != nullptr) {
            probe = probe->next;
            count ++;
            if(count%k == 0) {
                conn->next = reverseList(delayed, k, true);
                if(count/k == 1) first = conn->next;
                for(int i=0;i<k;i++) {conn = conn->next;}
                delayed = probe;
            }
        }
        conn->next = delayed;
        return first;
        
    }
    
    ListNode* reverseList(ListNode*head, int n, bool left){
        if(n==1) return head;
        if(n==2){
            ListNode *pre = head, *post = head->next;
            post->next = pre;
            if(left) return post;
            else return pre;
        }else{
            int half = n / 2, index = 0;
            ListNode *second = head, *end = head;
            while(index < n-1) {
                end=end->next;
                if(index<half)
                    second = second->next; 
                index++;
            }
            ListNode *left_half = reverseList(head, half, true), *right_half = reverseList(second, n-half, false);
            right_half->next = left_half;
            if(left) return end;
            else return head;
        }
    }
};