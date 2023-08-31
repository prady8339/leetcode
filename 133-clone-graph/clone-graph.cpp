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
        if(node == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(node->val);
        ump[node] = newNode;
        vector<Node*>& vec = newNode->neighbors;
        for(auto& neighbor : node->neighbors) {
            if(ump.find(neighbor) == ump.end()) {
                Node* addNode = cloneGraph(neighbor);
                vec.push_back(addNode);
            }
            else {
                if(find(vec.begin(), vec.end(), ump[neighbor]) == vec.end()) {
                    vec.push_back(ump[neighbor]);
                }
            }
        }
        return newNode;
    }
};