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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* a=head,*b=head->next;
        a->next = NULL;
        while(b!=NULL){
            ListNode* temp = b->next;
            b->next = a;
            a=b;
            b=temp;
        }
        return a;
    }
};