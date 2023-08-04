/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };4
 */
class Solution {
    private:
    ListNode* solve(ListNode* root){

            if (root == nullptr || root->next == nullptr) return root;
        ListNode* curr = solve(root->next);
        root->next->next = root;
        root->next = nullptr;
        return curr;
        // if(root==NULL || root->next==NULL ) return root;
        // ListNode* curr = solve(root->next);
        // curr->next = root;
        // return curr;
    }

   
public:
    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};