class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int smallest=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==smallest)
            smallest++;
        }
        return smallest;
    }
};
