class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum^=nums[i];
        }
        return sum;
    }
};
