
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Square all elements
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Sort the squared elements
        sort(nums.begin(), nums.end());

        // Step 3: Return the sorted array
        return nums;
    }
};
