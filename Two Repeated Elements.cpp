class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        // Your code here
        vector<int> ans;
        sort(arr,arr+n+2);
        for(int i=1;i<n+2;i++){
            if(arr[i]==arr[i-1])
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
