//Rotate a Matrix by 180 Counterclockwise

/*Given a 2D square matrix mat[][] of size n x n, turn it by 180 degrees without using extra space.

Note: You must rotate the matrix in place and modify the input matrix directly.*/
+++++++++++++++++++++++++++++++++++++++++++++++++++++++



  class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Calculate the position of the element to swap with
            int ni = n - 1 - i;
            int nj = n - 1 - j;

            // Swap only if the current element is in the "first half"
            if (i < ni || (i == ni && j < nj)) {
                swap(mat[i][j], mat[ni][nj]);
            }
        }
    }
    }
};
