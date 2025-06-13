class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int ans=0;
        for(int i=0;i<m;i++){
            if (n%2!=0)
                ans=ans^nums1[i];
            else
                break;
        }
        for (int i=0;i<n;i++)
            if( m%2!=0)
                ans=ans^nums2[i];
            else
                break;
                
        return ans;
    }
};
