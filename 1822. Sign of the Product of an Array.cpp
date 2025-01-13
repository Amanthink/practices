class Solution {
public:
    int arraySign(vector<int>& arr) {
        int m=0,p=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0)
            m++;
            if(arr[i]==0)
            return 0;
        }
        if(m%2==0)
        return 1;
        else 
        return -1;
    }
};
