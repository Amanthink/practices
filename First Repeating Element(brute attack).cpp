class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            int p=i+1;
            bool  ans=true;
            while(p<n){
                if(arr[i]==arr[p]){
                ans=false;
                p++;
                }
            }
            if(ans==true)
            return i;
            
        }
        return -1;
    }
};
