class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before_head, after_head; // dummy nodes
        ListNode *before = &before_head, *after = &after_head;
        
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = nullptr;  // Important! This prevents a cycle in the list.
        before->next = after_head.next;  // Concatenate before list and after list
        
        return before_head.next;
    }
};
