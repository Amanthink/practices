class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(k==1)
        return true;
        if(k==0)
        return false;
        sort(arr.begin(),arr.end());
        int start=0,end=arr.size()-1;
        while(start<end){
            int p=arr[start]+arr[end];
            if(p%k==0)
            return true;
            else if(end==start){
                end=arr.size()-1;
                start++;
            }
            else 
            end--;
            
        }
        return false;
    }
};
