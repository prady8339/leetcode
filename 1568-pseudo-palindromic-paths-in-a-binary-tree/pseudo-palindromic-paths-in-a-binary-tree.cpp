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
    int count = 0;
    int solve(TreeNode* root, unordered_map<int,int> &un){
        if(!root) return 0;

        un[root->val]++;
        if(un[root->val] % 2 == 0){
            count--;
        }else{
            count++;
        }

        if(!root->left && !root->right){
            un[root->val]--;
            int addon = 0;
            if(un[root->val] % 2 == 0){
                addon = -1;
            }else{
               addon = 1;
            }

            if(count <= 1){
                count += addon;
                return 1;
            }else{
                count += addon;
                return 0;
            }
        }

        int a = 0;
        a += solve(root->left, un);
        a += solve(root->right, un);

        un[root->val]--;
        if(un[root->val] % 2 == 0){
            count--;
        }else{
            count++;
        }

        return a;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> un;
        return solve(root,un);
    }
};