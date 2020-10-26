/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*
    Node* connect(Node* root) { // my method
        Node* start = root;
        while(start){
            if(!start->left && !start->right && !start->next) break;
            Node* curr = start, *prev=nullptr, *nextlevel = nullptr;
            while(curr){ // loop over within the level
                if(!curr->left && !curr->right) {curr = curr->next;continue;} // no childs, nothing to do, go next
                if(curr->left && curr->right) curr->left->next = curr->right; // two children, then connect them
                if(prev){ // has leftover pointer from the previous node
                    if(curr->left) prev->next = curr->left;
                    else prev->next = curr->right; // connect the prev pointer
                    while(prev->next) prev=prev->next; //update it
                }else { // no valid previous leftover pointer, simply update it
                    prev = (curr->right ? curr->right : curr->left);
                    if(!nextlevel) nextlevel = (curr->left ? curr->left : curr->right); // store the leftmost node of the next level
                }
                curr = curr->next;
            }
            start = nextlevel;
        }
        return root;
    }
    */
    /*
    Node* connect(Node* root) { // official solution, more clear
        Node* start = root;
        while(start){
            Node* nextlevel = nullptr, *prev=nullptr;
            for(;start;start=start->next){
                if(start->left) helper(prev, start->left, nextlevel);
                if(start->right) helper(prev, start->right, nextlevel);
            }
            start = nextlevel;
        }
        return root;
    }

    void helper(Node* &prev, Node* &p, Node* &nextlevel){
        if(prev) prev->next = p;
        if(!nextlevel) nextlevel = p;
        prev = p;
    }
    */
    Node* connect(Node* root) { // another method, here level concept is not very clear.
        Node *head = new Node(0, NULL, NULL, NULL); // acts like "prev" pointer
        Node *p = root, *cur = head; // curr starts from the head node
        while(p){
            if(p -> left){
                cur -> next = p -> left;
                cur = cur -> next;
            }
            if(p -> right){
                cur -> next = p -> right;
                cur = cur -> next;
            }

            p = p -> next;
            if(!p){ // reached the end of one level
                p = head -> next; // move p to the next level node
                head -> next = NULL; // clear head link
                cur = head; // reset cur to the head
            }
        }
        return root;
    }
};
