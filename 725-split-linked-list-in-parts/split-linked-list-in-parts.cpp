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
        vector<ListNode*> ans(k,NULL);
        ListNode* curr = head;
        int n = 0;
        while(curr){
            curr = curr -> next;
            n++;
        }
        int hd = n/k, r = n%k;
        curr = head;
        ListNode* prev = NULL;
        for (int i = 0; curr && i < k; i++, r--) {
            ans[i] = curr;
            for (int j = 0; j < hd + (r > 0); j++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};