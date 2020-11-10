/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<int, Node*> visited;
    /*
    Node* cloneGraph(Node* node) { // DFS
        if(!node) return nullptr;
        int v = node->val;
        //cout << node->val << endl;
        visited[v] = new Node(v);
        for(auto n : node->neighbors){
            if(visited.find(n->val) == visited.end()) cloneGraph(n);
            visited[v]->neighbors.push_back(visited.find(n->val)->second);
        }
        return visited[v];
    }
    */
    Node* cloneGraph(Node* node) { // BFS
        if(!node) return nullptr;
        queue<Node*> frontiers;
        frontiers.push(node);
        visited[node->val] = new Node(node->val);
        while(!frontiers.empty()){
            Node* old = frontiers.front();
            frontiers.pop();
            for(auto n:old->neighbors){ // is to add neighbors
                if(visited.find(n->val)==visited.end()) { // the node has not been visited, new it and push into queue
                    visited[n->val] = new Node(n->val);
                    frontiers.push(n);
                }
                visited[old->val]->neighbors.push_back(visited[n->val]);
            }
        }
        return visited[node->val];
    }
};
