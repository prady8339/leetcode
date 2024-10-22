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
private:
    void solve(TreeNode* root, unordered_map<int, long long>& temp, int depth) {
        if (root == NULL)
            return;
        if (temp.count(depth))
            temp[depth] += root->val;
        else
            temp[depth] = root->val;
        solve(root->left, temp, depth + 1);
        solve(root->right, temp, depth + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> temp;
        solve(root, temp, 0);
        vector<long long> vec;
        for (auto& [k, v] : temp) {
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end());
        if (k > vec.size())
            return -1;
        return vec[vec.size() - k];
    }
};