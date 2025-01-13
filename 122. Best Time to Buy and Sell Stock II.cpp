class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                profit+=arr[i]-arr[i-1];
            }
        }
        return profit;
    }
};
