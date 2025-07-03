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
public:
    TreeNode* searchBST(TreeNode* root, int al) {
        if(root==NULL) return NULL;
        if(root->val==al) return root;
        else if(root->val<al) return searchBST(root->right,al);
        else if(root->val>al) return searchBST(root->left,al);
        return NULL;
    }
};
