class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN,curr_sum=0;;
        for(int start=0;start<nums.size();start++){
            curr_sum+=nums[start];
            max_sum=max(curr_sum,max_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return max_sum;
    }
}
