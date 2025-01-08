class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
         int n = arr.size();
    if (n < 3) return 0; // Not enough sides to form a triangle

    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    int count = 0;

    // Step 2: Fix the largest side
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;

        // Step 3: Use two pointers to find valid triangles
        while (i < j) {
            if (arr[i] + arr[j] > arr[k]) {
                // All pairs (i, i+1, ..., j) are valid
                count += (j - i);
                j--; // Move the right pointer left
            } else {
                i++; // Move the left pointer right
            }
        }
    }

    return count;
    }
};
