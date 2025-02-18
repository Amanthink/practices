class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        int res = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                res += (right - left);  
                left++;  
            } else {
                right--;  
            }
        }
        return res;
    }
};
