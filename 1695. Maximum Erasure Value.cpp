class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_map<int,int>mpp;
       int max_sum=0;
       int n=nums.size();
       int l=0,r=0;
       int sum=0;
       while(r<n){
            mpp[nums[r]]++;
        sum+=nums[r];
        while(mpp[nums[r]]>1){
            mpp[nums[l]]--;
            sum-=nums[l];
            l++;
        }
        max_sum=max(max_sum,sum);
        r++;
       }
       return max_sum;
    }
};
