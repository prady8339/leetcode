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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode *temp = head;
        head = new ListNode(0);
        head->next = temp;
        ListNode* prev = head;
        while(temp != NULL){
            if(st.count(temp->val)){
                prev->next = temp->next;
                temp=temp->next;
                continue;
            }  
            prev = temp;
            temp=temp->next;
        }
        return head->next;
    }
};