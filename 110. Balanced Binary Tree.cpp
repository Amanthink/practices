class Solution {
public:
    // Helper function to compute height and check balance
    int check(TreeNode* root) {
        if (!root) return 0; // base case

        int left = check(root->left);
        if (left == -1) return -1; // left subtree is unbalanced

        int right = check(root->right);
        if (right == -1) return -1; // right subtree is unbalanced

        if (abs(left - right) > 1) return -1; // current node is unbalanced

        return max(left, right) + 1; // return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
