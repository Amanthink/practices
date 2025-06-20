class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();             
        if (rows == 0) return 0;
        int cols = grid[0].size();           

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {      
                    count++;
                    callBFS(grid, i, j);
                }
            }
        }
        return count;
    }

    void callBFS(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

       
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        
        callBFS(grid, i + 1, j); // down
        callBFS(grid, i - 1, j); // up
        callBFS(grid, i, j + 1); // right
        callBFS(grid, i, j - 1); // left
    }
};
