class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        if(nums.size()==2)
        return -1;
      for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int ls=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(sum==ls)
            return i;
            ls+=nums[i];
        }
        return -1;
    }
};
