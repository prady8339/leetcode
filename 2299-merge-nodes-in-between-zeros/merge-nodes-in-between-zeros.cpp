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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = head, *nhead = NULL, *remp = NULL;
        while(temp != NULL){
            if(temp->val == 0 && temp!=head){
                if(nhead == NULL){
                    nhead = new ListNode(sum);
                    remp = nhead;
                }else{
                    remp->next = new ListNode(sum);
                    remp=remp->next;
                }
                sum = 0;
            }
            sum += temp->val;
            temp = temp->next;
        }
        return nhead;
    }
};