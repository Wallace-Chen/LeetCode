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
        vector<int> num1, num2;
        ListNode *p = l1, *q = l2;
        while(p!=nullptr || q!= nullptr){
            if(p!=nullptr){
                num1.push_back(p->val);
                p = p->next;
            }
            if(q!=nullptr){
                num2.push_back(q->val);
                q = q->next;
            }
        }
        int carry = 0;
        ListNode *curr = new ListNode();
        while(!num1.empty() || !num2.empty()){
            int x = 0;
            if(!num1.empty()) {x = num1.back(); num1.pop_back();}
            int y = 0;
            if(!num2.empty()) {y = num2.back(); num2.pop_back();}
            carry = x + y + carry;
            curr->val = carry%10;
            ListNode *tmp = new ListNode(0, curr);
            curr = tmp;
            carry /= 10;
        }
        if(carry>0) curr->val = carry;
        else curr = curr->next;
        
        return curr;
    }
};