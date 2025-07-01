class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are null
        if (!p && !q) return true;

        // One is null, the other isn't
        if (!p || !q) return false;

        // Both not null: compare values and subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
