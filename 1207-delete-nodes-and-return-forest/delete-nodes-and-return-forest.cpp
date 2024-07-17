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
void solve(vector<TreeNode*> &ans,TreeNode* root,unordered_set<int> &st,TreeNode* parent){

    if(root == NULL) return ;

    if(st.count(root->val)){
        if(root->right != NULL && !st.count(root->right->val)){
            ans.push_back(root->right);
        } 
        if(root->left != NULL && !st.count(root->left->val)){
            ans.push_back(root->left);
        }
        if(parent->left != NULL && parent->left == root){
            parent->left = NULL;
        }
        if(parent->right != NULL && parent->right == root){
            parent->right = NULL;
        }
    }

    solve(ans,root->left,st,root);
    solve(ans,root->right,st,root);

}
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        if(root!=NULL && !st.count(root->val))
        ans.push_back(root);
        solve(ans,root,st,root);
        return ans;
    }
};