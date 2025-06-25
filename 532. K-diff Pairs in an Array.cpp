class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // Edge case: absolute difference can't be negative
        if (k < 0) return 0;

        // Step 1: Store the frequency of each number in the input array
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int count = 0; // To count unique pairs with absolute difference k

        // Step 2: Traverse the frequency map
        for (auto [num, f] : freq) {
            if (k == 0) {
                // Case 1: Looking for duplicate numbers (i.e., nums[i] == nums[j])
                // If a number appears more than once, it's a valid pair
                if (f > 1) count++;
            } else {
                // Case 2: Looking for a number such that (num + k) also exists
                // This ensures |num - (num + k)| == k
                if (freq.count(num + k)) count++;
            }
        }

        // Step 3: Return total count of unique valid pairs
        return count;
    }
};
