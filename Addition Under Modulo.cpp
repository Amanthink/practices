class Solution {
public:
    long long sumUnderModulo(long long a, long long b) {
        const long long MOD = 1000000007;
        return (a % MOD + b % MOD) % MOD;
    }
};
