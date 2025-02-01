class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        for(int i=1;i<n;i++){
            if(nums[i]%2==0&&nums[i-1]%2==0)
                flag=false;
            
            if(nums[i]%2!=0&&nums[i-1]%2!=0)
                flag=false;
        }
        return flag;
    }
};
