class Solution {
  public:
  void reverse(int arr[],int low,int high){
      
      while(low<high)
      swap(arr[low],arr[high]);
      
  }
    void reverseInGroups(vector<int> &arr, int k) {
        // code 
        
        int n=arr.size();
        int low=0,high=k;
        while(low<n){
        reverse(arr,low,high-1);
        low+=k;
        high+=k;
        }
        
        
    }
};
