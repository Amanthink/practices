class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());  // Sorting the array

        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;  // Initialize two pointers
            
            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];

                if (sum == 0) return true;  // Triplet found
                else if (sum < 0) low++;    // Increase sum by moving `low` right
                else high--;               // Decrease sum by moving `high` left
            }
        }

        return false;  // No triplet found
    }
};
