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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *before = NULL, *after = NULL;
        ListNode *before_head=NULL,*after_head=NULL;

        ListNode *temp = head;
        while (temp) {
            if (temp->val < x) {
                if(!before_head){
                    before_head=temp;
                    before=before_head;
                }else{
                    before->next=temp;
                    before = before->next;
                }
               
                
            } else {

                if(!after_head){
                    after_head=temp;
                    after=after_head;
                }else{
                    after->next = temp;
                    after=after->next;
                }  
                
            }
            temp = temp->next;
        }

        if(after)
        after->next = NULL;  
        
        if(before)
        before->next = after_head; 
        else return head;

        return before_head;
    }
};
