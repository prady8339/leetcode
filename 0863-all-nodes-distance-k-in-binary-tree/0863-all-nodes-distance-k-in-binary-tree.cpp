/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
void solve(vector<int> &ans,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis,int src,int steps,int k){
    if(steps==k){
        ans.push_back(src);
        return;
    }
    vis[src]=1;
    for(auto ne:adj[src]){
        if(!vis[ne])
        solve(ans,adj,vis,ne,steps+1,k);
    }
}

    void createAdj(TreeNode *root,unordered_map<int,vector<int>> &adj){
        if(root==NULL) return ;
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        createAdj(root->left,adj);
        createAdj(root->right,adj);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> vis;
        createAdj(root,adj);
        int src = target->val;
        vector<int> ans;
        solve(ans,adj,vis,src,0,k);
        return ans;
    }
};




