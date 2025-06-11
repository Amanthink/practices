class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int>& result) {
        if (!root) return;  
              helper(root->left, result);

       
        helper(root->right, result);
         result.push_back(root->val);
    }
};
