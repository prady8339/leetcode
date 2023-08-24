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
    int height(TreeNode* root,int &dia){
        if(root==NULL) return 0;
        int l = height(root->left,dia);
        int r = height(root->right,dia);
        int temp = max(l,r)+1;
        int ans = max(temp,1+l+r);
        dia = max(dia,ans);
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = INT_MIN;
        height(root,dia);
        return dia-1;
    }
};