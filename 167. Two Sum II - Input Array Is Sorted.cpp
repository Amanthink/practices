class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> ans;
        int n = num.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int sum = num[low] + num[high];
            if (sum < target) {
                low++;
            } else if (sum > target) {
                high--;
            } else {
                ans.push_back(low+1);  // Store indices instead of values
                ans.push_back(high+1);
                break; // Exit after finding the first pair
            }
        }
        return ans;
    }
};
