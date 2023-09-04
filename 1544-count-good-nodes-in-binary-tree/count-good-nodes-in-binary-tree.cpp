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
    int helper(TreeNode* root,int maxi){
        if(!root) return 0;

        int count = 0;
        if(root->val >= maxi) count = 1;

        int l =  helper(root->left,max(maxi,root->val));
        int r =  helper(root->right,max(maxi,root->val));

        return l+r+count;
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};