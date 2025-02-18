class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n/2),right(n/2),ans(n);
        int p=0,q=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
            left[p]=nums[i];
            p++;}
            else{
                right[q]=nums[i];
                q++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0)
            ans[i]=left[i/2];
            else
            ans[i]=right[i/2];
        }
        return ans;
    }
};
