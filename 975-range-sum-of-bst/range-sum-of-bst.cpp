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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            auto tp = q.front();
            if(tp->val >= low && tp->val <= high){
                sum += tp->val;
            }
            if(tp->left){
                q.push(tp->left);
            }
            if(tp->right){
                q.push(tp->right);
            }
            q.pop();
        }
        return sum;
    }
};