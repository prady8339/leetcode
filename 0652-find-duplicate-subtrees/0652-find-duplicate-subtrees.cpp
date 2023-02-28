class Solution {
private:
    string inorderTraversal(TreeNode* root, unordered_map<string, int>& count, set<TreeNode*>& ans) {
        if (root == NULL) return "#";
        string s = to_string(root->val) + "," + inorderTraversal(root->left, count, ans) + "," + inorderTraversal(root->right, count, ans);
        if (++count[s] == 2) ans.insert(root);
        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> count;
        set<TreeNode*> ans;
        inorderTraversal(root, count, ans);
        return vector<TreeNode*>(ans.begin(), ans.end());
    }
};
