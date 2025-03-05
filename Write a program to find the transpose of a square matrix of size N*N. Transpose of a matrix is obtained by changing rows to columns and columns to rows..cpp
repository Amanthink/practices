class Solution {
  public:
    // Function to find transpose of a matrix.
    void transpose(vector<vector<int>>& mat, int n) {
        // code here
        for(int i = 0; i < n; i++) {  
        for(int j = i + 1; j < n; j++) {  
            swap(mat[i][j], mat[j][i]);
            }
        }
    }
};
