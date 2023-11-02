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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        auto lp = solve(root->left);
        auto rp = solve(root->right);

        int sum = lp.first + rp.first + root->val;
        int count =  lp.second + rp.second + 1;

        if( root->val == sum / count ) ans++;

        return {sum , count};
    }   
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};