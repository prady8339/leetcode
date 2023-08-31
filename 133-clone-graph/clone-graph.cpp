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
    unordered_map<Node*,Node*> ump;
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        if(ump.find(node) == ump.end()) {
            ump[node] = new Node(node->val);
            for(auto& neighbor : node->neighbors) {
                ump[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return ump[node];
    }
};