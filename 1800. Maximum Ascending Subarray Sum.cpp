class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0]; 
        int currentSum = nums[0]; 
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }
            res = max(res, currentSum);
        }

        return res;
    }
};
