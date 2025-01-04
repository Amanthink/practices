class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool checkEqual(vector<int>& arr, vector<int>& brr) {
        // code here
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        if(arr.size()!=brr.size())
        return false;
        else{
            for(int i=0;i<arr.size();i++){
                if(arr[i]!=brr[i])
                return false;
            }
        }
        return true;
    }
};
