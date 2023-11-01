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
    int ans = 0;
private:
   void isPal(vector<int> &v){
    //    for(int i = 1 ; i < 10 ; i++){
    //        cout<<v[i]<<" ";
    //    }
    //    cout<<endl;
       int odds = 0, evens = 0;
       int sz = 0;
       for(int i = 1; i <= 9 ; i++){
           if(v[i]&1){ odds++; if(odds>=2) return ; }
           else evens++;
           if(v[i]>0) sz+=v[i];
       }
      
       if(sz&1 && odds==1 ){
         ans++;
       }else if(sz>0 && odds==0){
           ans++;
       }
    }
    void dfs(TreeNode* root,vector<int> &v){
         if(!root){
            return;
        }
        if(!root->left && !root->right){
            v[root->val]++;
            isPal(v);
            v[root->val]--;
            return ;
        }
       

        v[root->val]++;
        dfs(root->left,v);
        dfs(root->right,v);
        v[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10);
        dfs(root,v);
        return ans;
    }
};