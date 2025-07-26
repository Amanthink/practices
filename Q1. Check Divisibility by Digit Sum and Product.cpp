class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int orig=n;
        while(n!=0){
            int temp=n%10;
            sum+=temp;
            product*=temp;
            n/=10;
        }
        int p=sum+product;
        if(orig%p==0) return true;
        return false;
    }
};
