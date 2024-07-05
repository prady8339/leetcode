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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        vector<int> ans = {1000000000, -1};
        int idx = 1;
        int firstIdx = -1;
        int prevIdx = -1;
        while (temp->next != NULL) {
            if (prev == NULL) {
                prev = temp;
                continue;
            }
            if (temp->val > prev->val && temp->val > temp->next->val) {
                if (firstIdx == -1)
                    firstIdx = idx;
                if (prevIdx != -1)
                    ans[0] = min(idx - prevIdx, ans[0]);
                prevIdx = idx;
            }
            if (temp->val < prev->val && temp->val < temp->next->val) {
                if (firstIdx == -1)
                    firstIdx = idx;
                if (prevIdx != -1)
                    ans[0] = min(idx - prevIdx, ans[0]);
                prevIdx = idx;
            }
            idx++;
            prev = temp;
            temp = temp->next;
        }
        if (ans[0] == 1000000000 || ans[0] == 0)
            ans[0] = -1;
        ans[1] = prevIdx - firstIdx;
        if (ans[1] == 0)
            ans[1] = -1;
        return ans;
    }
};