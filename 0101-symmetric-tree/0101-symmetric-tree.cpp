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
    bool check(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2==NULL) return 1;
        if((r1!=NULL && r2==NULL) || (r1==NULL && r2!=NULL) ) return 0;
        return (r1->val==r2->val) && check(r1->right,r2->left) && check(r1->left,r2->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);;
    }
};