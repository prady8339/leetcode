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
TreeNode* helper(vector<int>& preorder,vector<int> &inorder,int l,int r,int &idx){
    //where no elements left in inorder i.e NULL;
    if(l>r) return NULL;

    int root = preorder[idx];
    int piv = l;
    //find root in inorder
    while(inorder[piv] != root) piv++;

    // now we move to next root;
    idx++;

    TreeNode* node = new TreeNode(root);
    // inorder left to root is left part
    node->left =  helper(preorder,inorder,l,piv-1,idx);
    // inorder right to root is right part
    node->right = helper(preorder,inorder,piv+1,r,idx); 

    return node;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();
        return helper(preorder,inorder,0,n-1,idx);
    }
};