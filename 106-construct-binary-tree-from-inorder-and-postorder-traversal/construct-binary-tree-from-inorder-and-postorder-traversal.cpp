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
    TreeNode* helper(vector<int>& inorder,vector<int> &postorder,int l,int r,int &idx){
        if( l > r || idx>=inorder.size()) return NULL;

        int root = postorder[idx];
        //find root in inorder;
        int pi = l;
        while(inorder[pi] != root) pi++;

        // move to next root;
        idx--;

        TreeNode* node = new TreeNode(root);

        node->right = helper(inorder,postorder,pi+1,r,idx);
        node->left  = helper(inorder,postorder,l,pi-1,idx);

        return node;
    }

// TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l, int r, int& idx) {
//     if (l > r) return NULL;

//     int root = postorder[idx];
//     // Find root in inorder;
//     int pi = l;
//     while (inorder[pi] != root) pi++;

//     // Decrement idx before calling for the right subtree.
//     idx--;

//     TreeNode* node = new TreeNode(root);

//     node->right = helper(inorder, postorder, pi + 1, r, idx); // Corrected this line.
//     node->left = helper(inorder, postorder, l, pi - 1, idx);

//     return node;
// }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return helper(inorder,postorder,0,n-1,idx);
    }
};