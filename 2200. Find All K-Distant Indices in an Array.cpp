class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> ind(n+1);
        int left = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=max(i-k,left);j<=min(n-1,i+k);j++){
                    ind[j] = 1;
                }
                left = min(n-1,i+k);
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
