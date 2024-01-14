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
    Node* connect(Node* root) {
        if(!root) return NULL;
        unordered_map<int,vector<Node*>> ds;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto tp = q.front();
            int depth = tp.second;
            Node* curr = tp.first; 
            ds[depth].push_back(curr);
            if(curr->left){
                q.push({ curr->left , depth + 1});
            }
            if(curr->right){
                q.push({ curr->right, depth + 1});
            }
            q.pop();
        }
        cout<<ds.size();
        for(auto &[k, v] : ds){
            if(v.size() >= 2){
                for(int i = 0 ; i < v.size()-1 ; i++){
                    v[i]->next = v[i + 1];
                }
            }
           
        }
        return root;
    }
};