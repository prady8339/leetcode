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
private:
    Node* dfs(Node* node,unordered_map<Node*,Node*> &oldToNew){
        if(node==NULL) return NULL;
        if(oldToNew.count(node))
            return oldToNew[node];
        
        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;

        for(auto ne:node->neighbors){
            newNode->neighbors.push_back(dfs(ne,oldToNew));
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> oldToNew;
        return dfs(node,oldToNew);
    }
};