class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            int first = nums[i];
            int mid = nums[i + 1];
            int third = nums[i + 2];

            // Only check when mid is even
            if (mid % 2 == 0 && (first + third == mid / 2)) {
                count++;
            }
        }
        return count;
    }
};

