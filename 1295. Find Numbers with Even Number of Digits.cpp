class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            int j=0;
            int count=0;
            while(s[j]!=0){
                count++;
                j++;
            }
            if (count % 2 == 0) {
                ans++;
            }       
             }
        return ans;

    }
};
