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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;
        while(fast!=NULL && fast->next!=NULL){
            st.push(slow->val);
            fast = fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL) slow=slow->next;

        while(!st.empty() && slow!=NULL){
            if(st.top() != slow->val) return 0;
            st.pop();
            slow=slow->next;
        }
        return 1;
    }
};