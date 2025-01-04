class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        // Check if the first number is not 1, return 1 if it's missing
        if (arr[0] != 1) {
            return 1;
        }

        // Loop through the array to find the missing number
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] > 1) {
                return arr[i] + 1; // The missing number is the next one
            }
        }
        
        // If no missing number found, it must be n+1 (since 1 to n should be present)
        return arr[n - 1] + 1;
    }
};
