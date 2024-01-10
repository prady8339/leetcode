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
    TreeNode* getStart(TreeNode* root, int &start){
        if(!root) return NULL;
        if(root->val == start){
            return root;
        }
        TreeNode* a = getStart(root->left , start);
        TreeNode* b = getStart(root->right, start);
        if(a)
            return a;
        else
            return b;
    }
    void makeAdj(TreeNode *root,TreeNode *par, unordered_map<int,vector<TreeNode*>> &adj){
         if(!root) return ;
         int curr = root->val;
         if(root->left){
             adj[curr].push_back(root->left);
         }
         if(root->right){
             adj[curr].push_back(root->right);
         }
         if(par){
             adj[curr].push_back(par);
         }
         makeAdj(root->left,root, adj);
         makeAdj(root->right,root,adj);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st = getStart(root, start);
        unordered_map<int,vector<TreeNode*>> adj;
        makeAdj(root,NULL,adj);
        unordered_set<TreeNode*> vis;
        queue<pair<TreeNode*,int>> q;
        q.push({st, 0});
        int maxDepth = 0;
        while(!q.empty()){
            auto tp = q.front();
            TreeNode* curr = tp.first;
            int dist = tp.second;
            if(vis.count(curr)){
                q.pop();
                continue;
            }
            vis.insert(curr);
            maxDepth = max(maxDepth, tp.second );
            for(auto &n : adj[ tp.first->val ]){
                q.push({n , 1 + tp.second });
            }
            q.pop();
        }

        // for(auto [k, v] : adj){
        //     cout<<k<<": ";
        //     for(auto &vec : v){
        //         cout<<vec->val<<" ";
        //     }
        //     cout<<endl;
        // }
        return maxDepth;
    }
};