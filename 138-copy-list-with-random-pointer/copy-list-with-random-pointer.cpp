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
        while(temp!=NULL){
            Node* nx = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nx;
            temp = temp -> next-> next;
        }
        temp = head;
        Node* nhead = NULL;
        Node* remp = nhead;

        while(temp!=NULL){
            
            if(temp->random==NULL)
            temp->next->random=NULL;
            else{
             temp->next->random = temp->random->next;       
            }

            temp=temp->next->next;
            
        }

        temp = head;
        
        while(temp!=NULL){

            if(nhead==NULL){
                nhead=temp->next;
                remp = nhead;
            }else{
            remp->next = temp->next;
            remp=remp->next;
            }

            temp->next = temp->next->next;
            temp=temp->next;
        }

        return nhead;

    }
};