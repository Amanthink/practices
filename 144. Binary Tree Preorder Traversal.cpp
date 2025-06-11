class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
};
