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
    int maxi = 0;
void solve(unordered_map<int,int> &freq,TreeNode* root){
    if(!root) return ;
    freq[root->val]++;
    if(freq[root->val] > maxi) maxi = freq[root->val];
    solve(freq,root->left);
    solve(freq,root->right);
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        solve(freq,root);
        vector<int> ans;
        for(auto &[first,second]: freq){
            if(second==maxi){
                ans.push_back(first);
            }
        }
        return ans;
    }
};