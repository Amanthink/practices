class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;

        ans.push_back({1}); 
        for (int i = 1; i < numRows; i++) {
            vector<int> prev = ans[i - 1]; 
            vector<int> curr;
            curr.push_back(1); 
            for (int j = 1; j < i; j++) {
                curr.push_back(prev[j - 1] + prev[j]);
            }

            curr.push_back(1); 
            ans.push_back(curr);
        }

        return ans;
    }
};
