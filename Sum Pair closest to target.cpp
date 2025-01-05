class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int> ans(2); 
        int start = 0, end = arr.size() - 1;
        sort(arr.begin(), arr.end()); // Sort the array
        
        int closestDiff = INT_MAX; // Track the smallest difference
        
        while (start < end) {
            int sum = arr[start] + arr[end];
            int diff = abs(target - sum); // Absolute difference from target
            
            // Update closest pair if a closer sum is found
            if (diff < closestDiff) {
                closestDiff = diff;
                ans[0] = arr[start];
                ans[1] = arr[end];
            }
            
            // Adjust pointers based on the sum
            if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        
        return ans;
    }
};
