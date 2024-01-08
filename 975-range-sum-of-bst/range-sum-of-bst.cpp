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
    int preorder(TreeNode* root, int &low, int &high){
        if(!root) return 0;
        int sum = 0,add = 0;
        if(root->val >= low && root->val <= high)
        add = root->val;
        int a =  preorder(root->left,low,high);
        int b = preorder(root->right,low,high);
        return add + a + b;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root,low,high);
    }
};