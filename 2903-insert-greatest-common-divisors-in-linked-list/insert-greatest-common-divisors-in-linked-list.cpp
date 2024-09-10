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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
       ListNode* curr = head->next, *prev = head; 
       while(curr != NULL){
        int v = __gcd(curr->val, prev->val);
        prev->next = new ListNode(v);
        prev->next->next = curr;
        prev = curr;
        curr = curr->next;
       }
       return head;
    }
};