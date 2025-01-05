
//by using sort function
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
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//without using sort function
    class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

      
        for (int i = 0; i < nums.size() - 1; i++) {
            int mini = i; 
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[mini]) {
                    mini = j; 
                }
            }
            if (mini != i) {
                int temp = nums[mini];
                nums[mini] = nums[i];
                nums[i] = temp;
            }
        }

       
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};
