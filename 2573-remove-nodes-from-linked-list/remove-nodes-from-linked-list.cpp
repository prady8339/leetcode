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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> mono;
        ListNode* temp = head;
        while(temp != NULL){
            while(!mono.empty() && mono.top()->val < temp->val){
                mono.pop();
            }
            mono.push(temp);
            temp = temp -> next;
        }
        if(mono.empty()) return NULL;
        ListNode* nHead = mono.top();
        mono.pop();
        nHead->next = NULL;
        while(!mono.empty()){
            ListNode* remp = nHead;
            nHead = mono.top();
            nHead->next = remp;
            mono.pop();
        }
        return nHead;
    }
};