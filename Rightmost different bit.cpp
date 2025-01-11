
class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int count=0;
        if(m==n)
        return -1;
        while(m>0&&n>0){
            int r=m%2;
            int p=n%2;
            count++;
            if(r!=p){
            return count ;
            break;
            }
            m/=2;
            n/=2;
            if(m==0||n==0)
            return count+1;
        }
        return count;
    }
};
