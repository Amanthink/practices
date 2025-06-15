class Solution {
public:
    void inorder(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return arr;
    }
};
