class Solution {
public:
    int trap(vector<int>& arr) {
       const int n=arr.size();
        int res=0;
        int lmax[n],rmax[n];
        lmax[0]=arr[0];
        for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],arr[i]);
        rmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        rmax[i]=max(arr[i],rmax[i+1]);
        for(int i=0;i<n-1;i++)
        res+=(min(lmax[i],rmax[i])-arr[i]);
        return res;
    }
};
