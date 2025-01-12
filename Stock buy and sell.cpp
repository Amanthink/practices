class Solution {
  public:
    // Function to find the days of buying and selling stock for max profit.
    int stockBuySell(vector<int> &arr) {
        // code here
        int n=arr.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                profit+=arr[i]-arr[i-1];
            }
        }
        return profit;
    }
};
