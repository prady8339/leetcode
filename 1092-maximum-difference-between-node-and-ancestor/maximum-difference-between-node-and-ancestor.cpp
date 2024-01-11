/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root,int maxi,int mini){
        if(!root){
            return maxi - mini;
        }
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        return 
            max(
                solve(root->left, maxi, mini),
                solve(root->right, maxi, mini)
            );
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, 0, INT_MAX);
    }
};