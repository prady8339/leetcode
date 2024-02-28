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
    void solve(TreeNode* root,int x,int y,pair<int,pair<int,int>> &ans){
        if(!root) return;

        if(y > ans.first ){

            ans.first = y;
            ans.second = {x,root->val};
        }else if(y == ans.first && ans.second.first > x){
            // ans.first = y;
            // ans.second = {x,root->val};
        }

        solve(root->left, x -1 , y + 1, ans);
        solve(root->right, x + 1, y + 1, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        pair<int,pair<int,int> > ans ={0,{0,root->val}};
        solve(root,0,0,ans);
        return ans.second.second;
    }
};