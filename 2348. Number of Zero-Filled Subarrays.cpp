


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<unsigned int> streak(nums.size(),0);
        int idx=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else {
                if(count>0){ streak.push_back(count); count=0;}
            }
            }
            if (count > 0) streak.push_back(count);
            unsigned long long int ans=0;
            for(int i=0;i<streak.size();i++){
                ans+=(1ll*streak[i]*(streak[i]+1))/2;
            }
            return ans;
        }
        
    };
