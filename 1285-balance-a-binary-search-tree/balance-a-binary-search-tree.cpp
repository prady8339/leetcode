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
    vector<TreeNode*> nodes;
public:
    TreeNode* balanceBST(TreeNode* root) {
       inorder(root);
       return binaryFit(0,nodes.size() - 1);
    }

    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* binaryFit(int l, int r){
        if(l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = nodes[mid];
        root->left = binaryFit(l, mid - 1);
        root->right = binaryFit(mid + 1, r);
        return root;
    }


};