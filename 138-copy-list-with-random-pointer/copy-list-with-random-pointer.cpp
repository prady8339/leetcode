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
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*,Node*> un;
        while(temp!=NULL){
            un[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp!=NULL){
            un[temp]->next = un[temp->next];
            un[temp]->random = un[temp->random];
            temp=temp->next;
        }
        return un[head];
    }
};