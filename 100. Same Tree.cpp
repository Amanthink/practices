class Solution {
public:
    void preorder(TreeNode* node, vector<int>& arr) {
        if (!node) {
            arr.push_back(INT_MIN); // Marker for NULLs to preserve structure
            return;
        }
        arr.push_back(node->val);
        preorder(node->left, arr);
        preorder(node->right, arr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> arr1, arr2;
        preorder(p, arr1);
        preorder(q, arr2);
        return arr1 == arr2;
    }
};
