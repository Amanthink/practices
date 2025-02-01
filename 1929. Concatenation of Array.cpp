class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int p=0;
        while(p<2){
        for(int i=0;i<nums.size();i++)
        ans.push_back(nums[i]);
        p++;
        }
        return ans;
    }
};
