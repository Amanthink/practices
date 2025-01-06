class Solution {
  public:
    // Function to find the minimum value required to balance the array.
    int minValueToBalance(vector<int> &arr) {
        // code here
        int n=arr.size();
        int p=0;
        for(int i=0;i<n/2;i++){
         p+=arr[n-i-1]-arr[i];
        
        }
        if(p<0) p=-1*p;
        return p;
    }
};
