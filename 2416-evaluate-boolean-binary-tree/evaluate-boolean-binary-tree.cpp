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
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;

        bool c1 = false;
        bool c2 = false;

        if(root->left)
        c1 = evaluateTree(root->left);

        if(root->right)
        c2 = evaluateTree(root->right);

        if(root->val == 2){
            return c1 | c2;
        }
        if(root->val == 3){
            return c1 & c2;
        }
        return false;

    }
};