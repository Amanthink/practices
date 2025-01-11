class Solution{
  public:
    // Function to find element with more appearances between two elements in an
    // array.
    int majorityWins(int arr[], int n, int x, int y) {
        // code here
         int count=0,cou=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x)
            count++;
            else if(arr[i]==y)
            cou++;
        }
            if(count==cou)
            return min(x,y);
            else if(count>cou)
            return x;
            else 
            return y;
    }
};
