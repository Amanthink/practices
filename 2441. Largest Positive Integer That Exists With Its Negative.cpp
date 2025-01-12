class Solution {
public:
    int findMaxK(vector<int>& arr) {
        int ans = -1; 
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (arr[i] == -arr[j] && arr[i] > 0) {
                    ans = max(ans, arr[i]);
                }
            }
        }
        return ans;
    }
};
