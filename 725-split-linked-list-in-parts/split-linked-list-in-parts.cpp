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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       int sz = 0;
       ListNode* temp = head;
       while(temp != NULL){
        sz++;
        temp = temp->next;
       } 
       int md = sz % k;
       int n = sz / k;
       temp = head;
       vector<ListNode*> ans;
       for(int i = 0 ; i < k ; i++){
            int till = n;
            if(md > 0) till++;
            ListNode* nh = temp, *prev = temp;;
            while(temp != NULL && till > 0){
                prev = temp;
                temp=temp->next;
                till--;
            }
            md--;
            if(prev != NULL)
            prev->next = NULL;
            ans.push_back(nh);
       }
       return ans;
    }
};