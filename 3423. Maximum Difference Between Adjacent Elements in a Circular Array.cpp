class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int maxDiff = abs(nums[n - 1] - nums[0]);

        for (int i = 1; i < n; i++) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i - 1]));
        }

        return maxDiff;
    }
};
