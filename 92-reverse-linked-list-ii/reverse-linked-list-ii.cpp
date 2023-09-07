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
private: 
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        
        ListNode* node = new ListNode(0);
        node->next = head;
        head = node;


        int l = left ,r = right - left;

        ListNode* curr = head,*prev = head;
        while(curr && l>0){
            prev=curr;
            curr = curr->next;
            l--;
        }
        ListNode* slime = curr;
      
        while(curr && r>0){
            curr = curr->next;
            r--;
        }
        //cout<<curr->val;

        ListNode* remp = NULL;

        if(curr){
            remp = curr->next;
            curr->next = NULL;
        }
 

        prev->next = reverse(prev->next);
  

        if(curr){
            slime->next = remp;
        }

        return head->next;
    }   
};