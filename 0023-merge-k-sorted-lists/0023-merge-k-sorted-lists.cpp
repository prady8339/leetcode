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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vs; ListNode* temp = NULL;
        for(int i = 0 ; i < lists.size() ; i++){
        temp = lists[i];
            while(temp!=NULL){
                vs.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(vs.begin(),vs.end());
        ListNode* ans = NULL , *remp = NULL;
        for(int i = 0 ; i < vs.size() ; i++){
            if(ans==NULL){
                ans = new ListNode(vs[i]);
                remp = ans;
            }
            else{
                remp->next = new ListNode(vs[i]);
                remp = remp->next;
            }
           
        }
        return ans;
    }
};