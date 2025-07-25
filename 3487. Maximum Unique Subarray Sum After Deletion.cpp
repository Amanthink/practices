class Solution {
public:
    int maxSum(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n=nums.size();
         if(nums[n-1]<=0) return nums[n-1];
         int sum=(nums[0]>=0)?(nums[0]):(0);
         for(int i=1;i<nums.size();i++){
            if(nums[i]>0&&nums[i]!=nums[i-1]) sum+=nums[i];
         }
         return sum;
    }
};
