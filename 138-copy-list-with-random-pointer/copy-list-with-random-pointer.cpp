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
void print(Node* head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->val<<" ";
        curr = curr-> next;
    }
    return ;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* curr = head;
        Node* cpHead = NULL;

        while(curr != NULL){    
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while(curr != NULL){

            if(curr->random != NULL)
            curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        curr = head;
        Node* helper = NULL;

        while(curr != NULL){

            if(cpHead==NULL){
                cpHead = curr->next;
                helper=cpHead;
            }else{
                helper->next = curr->next;
                helper = helper->next;
            }
                
            curr->next = curr->next->next;
            curr = curr->next;
        }
        //print(cpHead);
        // cout<<endl;
        //  print(head);
        return cpHead;
    }
};