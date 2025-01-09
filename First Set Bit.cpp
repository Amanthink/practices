class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        int count=1;
        
        while(n!=0){
        if(n%2==1)
        return count;
        count++;
        n/=2;
        }
        return 0;
    }
};
