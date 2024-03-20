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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // a ke piche wala aur b ke agge wala
        ListNode* temp = list1;
        ListNode* prev = temp;
        b-=a;
        while(temp!=NULL && a>0){
            prev = temp;
            a--;
            temp = temp->next;
        }
        while(temp!=NULL && b>0){
            b--;
            temp=temp->next;
        }
        if(temp!=NULL)
        temp = temp->next;
        prev->next = list2;
        ListNode *remp = list2;
        while(remp->next != NULL){
            remp = remp->next;
        }
        remp->next = temp;
        return list1;
    }
};