/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       if(!head->next) return head;
       ListNode * temp = head,*remp=temp;
        while(remp!=NULL && remp->next!=NULL){
            temp=temp->next;
            remp=remp->next->next;
        }
        return temp;
    }
    
};