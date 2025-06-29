class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7; // To avoid integer overflow (as required by many problems)
        int n = nums.size();

        // Step 1: Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());

        // Step 2: Precompute powers of 2 up to n-1
        // pow2[i] = 2^i % MOD
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        int left = 0, right = n - 1; // Two pointers: smallest and largest element
        int count = 0; // To store the result (number of valid subsequences)

        // Step 3: Two-pointer technique
        while (left <= right) {
            // If min + max <= target, then all subsets formed with elements from
            // left to right (inclusive), where left is always included, are valid
            if (nums[left] + nums[right] <= target) {
                // Number of such subsequences = 2^(right - left)
                count = (count + pow2[right - left]) % MOD;
                left++; // Move to the next smallest number
            } else {
                // If sum > target, we need a smaller max, so move the right pointer
                right--;
            }
        }

        return count; // Final count of valid subsequences
    }
};
