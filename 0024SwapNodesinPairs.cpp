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

    ListNode* swapPairs(ListNode* curr) {
        if(curr==nullptr || curr->next == nullptr) return curr;
        ListNode *pre = curr, *post = curr->next;
        curr = curr->next->next;
        post->next = pre;
        pre->next = swapPairs(curr);
        return post;
    }
};