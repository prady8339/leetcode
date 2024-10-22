/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root)
            return -1;
        priority_queue<long long, vector<long long>, greater<long long>> mH;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                auto tp = q.front();
                q.pop();
                levelSum += tp->val;

                if (tp->left)
                    q.push(tp->left);
                if (tp->right)
                    q.push(tp->right);
            }

            if (mH.size() < k) {
                mH.push(levelSum);
            } else if (mH.size() >= k) {
                auto tp = mH.top();
                mH.pop();
                if (levelSum > tp)
                    mH.push(levelSum);
                else
                    mH.push(tp);
            }
        }
        if (mH.size() < k)
            return -1;
        return mH.top();
    }
};