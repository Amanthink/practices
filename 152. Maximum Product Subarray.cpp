class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int prod = 1;

        // Forward pass
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if(nums[i] == 0) prod = 1;
        }

        // Backward pass to handle cases like [-1, -2, -3] (odd number of negatives)
        prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if(nums[i] == 0) prod = 1;
        }

        return maxProd;
    }
};
