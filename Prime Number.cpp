class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1)
        return false;
        else{
            for(int i=2;i*i<=n;i++){
                if(n%i==0)
                return false;
            }
        }
        return true;
    }
};