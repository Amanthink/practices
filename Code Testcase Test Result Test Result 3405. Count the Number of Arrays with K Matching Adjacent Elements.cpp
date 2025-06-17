// dated 17 june.                                                      class Solution {
public:
    long long const mod = 1e9 + 7;

    long long power(long long a, long long b) {
        long long result = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }

    long long factorial(int n) {
        long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = (fact * i) % mod;
        }
        return fact;
    }

    long long modInverse(long long x) {
        return power(x, mod - 2);
    }

    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long num = factorial(n);
        long long denom = (factorial(r) * factorial(n - r)) % mod;
        return (num * modInverse(denom)) % mod;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;

        long long comb = nCr(n - 1, k);          // Choose k equal adjacent positions
        long long first = m % mod;               // First value choices
        long long rest = power(m - 1, n - k - 1); // Remaining values not equal to previous

        return (comb * first % mod * rest % mod) % mod;
    }
};
