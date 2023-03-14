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
    int ss = 0;
    private:
        void solve(string help,TreeNode* root){
        if(root==NULL) { cout<<help<<endl; return ; }
         help+=to_string(root->val);
        if(!root->left && !root->right){
           ss+=stoi(help);
           return ;
        }
       
        solve(help,root->left);
        solve(help,root->right);

        }
    
public:
    int sumNumbers(TreeNode* root) {
        string help;
        solve(help,root);
        return ss;
    }
};