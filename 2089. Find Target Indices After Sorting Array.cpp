class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        // Sort the array using STL sort
        sort(nums.begin(), nums.end());
        
        // Find target indices
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};
