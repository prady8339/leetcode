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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(1){
            if(fast==NULL || fast->next==NULL ) return 0;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return 1;
        }
        return 1;
    }
};