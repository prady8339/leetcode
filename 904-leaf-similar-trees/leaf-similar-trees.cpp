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
    void preOrder(TreeNode* root, vector<int> &ab){
        if(!root) return ;
        if(!root->left && !root->right){
            ab.push_back(root->val);
        }
        preOrder(root->left, ab);
        preOrder(root->right, ab);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        preOrder(root1,a);
        preOrder(root2,b);
        if(a.size() != b.size()) return false;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};