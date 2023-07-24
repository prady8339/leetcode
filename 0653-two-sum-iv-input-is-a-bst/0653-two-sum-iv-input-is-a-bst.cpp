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
    void travel(TreeNode* root, unordered_map<int,int> &un){
        if(root==NULL) return ;
        un[root->val]++;
        travel(root->left,un);
        travel(root->right,un);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> un;
        travel(root,un);
        for(auto x:un){
            if(un.count(k-x.first) ) {
                auto temp = un.find(k-x.first);
              if(temp->first == x.first && x.second<=1) continue;
                return 1;
            }
        }
        return 0;
    }
};