class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<pair<int, int>> nums; // {value, index}
        for (int i = 0; i < arr.size(); ++i) {
            nums.push_back({arr[i], i});
        }
        sort(nums.begin(), nums.end());

        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int sum = nums[left].first + nums[right].first;
            if (sum == target) {
                return {nums[left].second, nums[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
