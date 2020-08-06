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
typedef pair<int, int> PAIR;
auto cmp = [](const PAIR &a, const PAIR &b) {
    return a.second > b.second;
};
typedef priority_queue<PAIR, vector<PAIR>, decltype(cmp)> min_heap;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        //if(len == 0) return nullptr;
        if(len == 1) return lists[0];
        min_heap hp(cmp);
        for(int i=0;i<len;i++) if(lists[i] != nullptr) hp.push({i, lists[i]->val});
        if(hp.size()>0) return mergeKLists(lists, hp);
        else return nullptr;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, min_heap& hp) {
        if(hp.size() == 1) return lists[hp.top().first];
        int i = hp.top().first;
        ListNode *head = lists[i]; hp.pop();
        if(lists[i]->next != nullptr) hp.push({i, head->next->val});
        lists[i] = lists[i]->next;
        head->next = mergeKLists(lists, hp);
        return head;
    }
    
};