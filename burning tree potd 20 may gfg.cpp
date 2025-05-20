class Solution {
  public:
    int Time = 0;
    
    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int findlength(Node* root, int target) {
        if (root==NULL) return -1;

        if (root->data == target) {
            int subtreeHeight = height(root);
            Time = max(Time, subtreeHeight - 1);  
            return 1;  
        }

        int leftDist = findlength(root->left, target);
        if (leftDist != -1) {
            int rightHeight = height(root->right);
            Time = max(Time, leftDist + rightHeight);
            return leftDist + 1;
        }

        int rightDist = findlength(root->right, target);
        if (rightDist != -1) {
            int leftHeight = height(root->left);
            Time = max(Time, rightDist + leftHeight);
            return rightDist + 1;
        }

        return -1;
    }

    int minTime(Node* root, int target) {
        Time = 0;
        findlength(root, target);
        return Time;
    }
};

