class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
         if (arr.empty()) return 0; // Handle edge case of empty array

        sort(arr.begin(), arr.end()); // Sort the array
        int res = 1; // Result to store the longest consecutive sequence
        int count = 1; // Counter for the current sequence

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                continue; // Skip duplicates
            }
            if (arr[i] == arr[i - 1] + 1) {
                count++; // Increment count for consecutive numbers
            } else {
                res = max(res, count); // Update the result
                count = 1; // Reset count for the new sequence
            }
        }

        res = max(res, count); // Check the last sequence
        return res;
    }
};
