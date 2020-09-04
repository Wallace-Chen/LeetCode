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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *slow = nullptr, *fast = head;
        int cnt=0;
        while(fast){
            cnt = 0;
            while(fast->next && fast->next->val == fast->val){
                fast = fast->next;
                cnt ++;
            }
            if(cnt == 0)  {
                if(slow != nullptr) slow->next = fast;
                else head = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        if(cnt == 0 && slow)  slow->next = fast;
        else if(slow) slow->next = nullptr;
        return slow ? head : nullptr;
    }
};
