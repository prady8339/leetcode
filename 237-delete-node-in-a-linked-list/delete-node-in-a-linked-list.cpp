/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* prev = node;
        temp = temp->next;
        while(temp->next != NULL){
            //swap
            int x = prev->val;
            prev->val = temp->val;
            temp->val = x;
            prev = temp;
            temp = temp->next;
        }
        int x = prev->val;
        prev->val = temp->val;
        temp->val = x;

        if(temp->next == NULL){
            prev->next = NULL;
            delete temp;
        }
    }
};