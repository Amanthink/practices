class Solution{
    public:
        int multiplicationUnderModulo(long long a,long long b)
    {
        //your code here
        const long long mod=1000000007;
        return ((a%mod)*(b%mod))%mod;
    }
};
