class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int p=nums[0];
       
        while(p>0){
            if(nums[0]%p==0&&nums[n-1]%p==0)
            break;
            p--;
        }
        return p;
    }
};
