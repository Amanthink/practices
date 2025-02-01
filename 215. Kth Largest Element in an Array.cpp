class Solution {
public:
    int findKthLargest(vector<int>& ans, int k) {
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return ans[n-k];
    }
};
