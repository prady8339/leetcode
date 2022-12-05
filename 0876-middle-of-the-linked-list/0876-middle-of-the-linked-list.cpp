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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return head;
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;
        }
        
        return v[v.size()/2];
    }
};