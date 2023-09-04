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
    int helper(TreeNode* root,int &maxi){
        if(root->left == NULL && root->right == NULL) return 0;

        int l = 0,r = 0;
        if(root->left!=NULL)
        l = 1+helper(root->left,maxi);
        if(root->right!=NULL)
        r = 1+helper(root->right,maxi);

        maxi = max(l+r,maxi);

        return max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root,maxi);
        return maxi;
    }
};