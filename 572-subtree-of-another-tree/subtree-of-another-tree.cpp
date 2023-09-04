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
    bool equalTree(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (!q && p)) return false;
        if(p->val != q->val) return false;
        bool l = equalTree(p->left,q->left);
        bool r = equalTree(p->right,q->right);
        return l && r;
    }
    bool helper(TreeNode* p,TreeNode *q){
        if(!p) return false;
        bool l = helper(p->left,q) || equalTree(p,q);
        bool r = helper(p->right,q) || equalTree(p,q);
        return l || r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};