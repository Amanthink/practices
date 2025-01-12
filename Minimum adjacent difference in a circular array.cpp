class Solution {
public:
    // Function to find minimum adjacent difference in a circular array.
    int minAdjDiff(int arr[], int n) {    
        // Initialize result with a large value
        int res = abs(arr[1] - arr[0]);

        // Iterate through the array
        for (int i = 1; i < n; i++) {
            // Calculate difference between current and previous elements
            res = min(res, abs(arr[i] - arr[i - 1]));
        }

        // Check the circular condition (last and first elements)
        res = min(res, abs(arr[n - 1] - arr[0]));
        
        return res;
    }
};
