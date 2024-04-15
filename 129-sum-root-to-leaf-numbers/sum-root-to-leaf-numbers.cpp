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
    int sum = 0;
private:
    void solve(TreeNode* root,string temp){
        if(root == NULL) {
            return ;
        }
        temp += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            sum += stoi(temp);
            return ;
        }
        solve(root->left , temp);
        solve(root->right, temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return sum;
    }
};