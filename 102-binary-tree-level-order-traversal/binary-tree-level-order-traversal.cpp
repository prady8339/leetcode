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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            for(int i = 0 ; i < sz ; i++){
                TreeNode *tp = q.front();
                temp.push_back(tp->val);
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};