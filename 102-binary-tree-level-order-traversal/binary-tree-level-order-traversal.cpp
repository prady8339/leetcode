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

        TreeNode *curr = root;
        unordered_map<int,vector<int>> ds;
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto tp = q.front();
            ds[tp.second].push_back(tp.first->val);
            q.pop();

            if(tp.first->left!=NULL){
                q.push({tp.first->left,tp.second+1});
            }
            if(tp.first->right!=NULL){
                q.push({tp.first->right,tp.second+1});
            }
        }

        for(int i = 0 ; i < ds.size() ; i++){
            vector<int> temp;
            for(auto x: ds[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};