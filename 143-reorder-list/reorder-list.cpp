class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // break the link
        
        // Step 2: Reverse the second half of the linked list
        secondHalf = reverseList(secondHalf);
        
        // Step 3: Merge the first half with the reversed second half
        mergeLists(head, secondHalf);
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = nullptr;
        
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }
    
    void mergeLists(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        bool flag = true; // flag to indicate whether we are taking node from first or second list
        
        while (first != nullptr && second != nullptr) {
            if (flag) {
                current->next = first;
                first = first->next;
            } else {
                current->next = second;
                second = second->next;
            }
            current = current->next;
            flag = !flag;
        }
        
        if (first != nullptr)
            current->next = first;
        
        if (second != nullptr)
            current->next = second;
        
        first = dummy->next;
        delete dummy;
    }
};
