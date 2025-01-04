class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int p=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>p)
            p=arr[i];
        }
        return p;
        
    }
};
