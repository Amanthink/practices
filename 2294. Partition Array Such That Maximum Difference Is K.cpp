class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
       
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int count = 0;
        int n = nums.size();

        int i = 0;
        while (i < n) {
            int start = nums[i];
            count++;
            while (i < n && nums[i] - start <= k) {
                i++;
            }
        }

        return count;
    }
};
