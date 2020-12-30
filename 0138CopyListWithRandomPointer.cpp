/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
    Node* copyRandomList(Node* head) { // two scans
        if(!head) return nullptr;
        vector<Node*> vec;
        Node* curr = head;
        while(curr){ // copy the list as normal
            vec.push_back(new Node(curr->val));
            int len = vec.size();
            if(len>1) vec[len-2]->next = vec[len-1];
            curr->val = len-1;
            curr = curr->next;
        }
        curr = head;
        int pos = 0;
        while(curr){ // add random pointers
            if(curr->random) vec[pos]->random = vec[curr->random->val];
            pos++;
            curr = curr->next;
        }
        return vec[0];
    }
    
    Node* copyRandomList(Node* head) { // treat it as a graph, and do DFS scan
        if(!head) return nullptr;
        
        static unordered_map<Node*, Node*> visited;
        if(visited.find(head)!=visited.end()){ // has visited
            return visited[head];
        }
        Node* tmp = new Node(head->val);
        visited.insert({head, tmp});
        tmp->next = copyRandomList(head->next);
        tmp->random = copyRandomList(head->random);
        
        return tmp;
    }
    
    unordered_map<Node*, Node*> visited;
    Node* getClonedNode(Node* head){
        if(!head) return nullptr;
        if(visited.find(head)!=visited.end()) return visited[head];
        else{
            Node* tmp = new Node(head->val);
            visited.insert({head, tmp});
            return tmp;
       }
    }
    Node* copyRandomList(Node* head) { // iteratively method
        if(!head) return nullptr;
        
        Node* start = new Node(head->val), *curr=head;
        visited.insert({curr, start});
        while(curr){
            start->random = getClonedNode(curr->random);
            start->next = getClonedNode(curr->next);
            curr = curr->next;
            start = start->next;
        }
        
        return visited[head];
    }*/
    Node* copyRandomList(Node* head) { // weaved list to mimic the corresponding between new and old list
        if(!head) return nullptr;
        
        Node* curr = head;
        while(curr){ // make weaved list
            Node* tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        
        // Now construct random, pointers
        curr = head;
        Node* cloned = curr;
        while(curr){
            cloned = curr->next;
            cloned->random = curr->random ? curr->random->next : nullptr;
            curr = cloned->next;
        }
        
        // Now construct next pointers
        curr = head;
        cloned = head->next;
        Node* ret = cloned;
        while(curr){ // remember to restore the original list
            curr->next = cloned->next;
            curr=curr->next;
            
            cloned->next = curr ? curr->next : nullptr;
            cloned = cloned->next;
        }
        return ret;
    }
    
};
