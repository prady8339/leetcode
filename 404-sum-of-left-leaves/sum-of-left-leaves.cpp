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
    void solve(TreeNode* root,int &sum,bool isLeft){
        if(!root) return ;
        if(root->left == NULL && root->right == NULL){
            if(isLeft)
            sum+= root->val;
            return ;
        }
        if(root->left){
            solve(root->left,sum,true);
        }
        if(root->right){
            solve(root->right,sum,false);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum,false);
        return sum;
    }
};