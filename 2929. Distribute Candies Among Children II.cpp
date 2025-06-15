class Solution {
public:
long long nCr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
    long long distributeCandies(int n, int limit) {
        auto total = nCr(n + 2, 2);
    auto overA = nCr(n - (limit + 1) + 2, 2);
    auto overB = nCr(n - (limit + 1) + 2, 2);
    auto overC = nCr(n - (limit + 1) + 2, 2);

    auto overAB = nCr(n - 2 * (limit + 1) + 2, 2);
    auto overAC = nCr(n - 2 * (limit + 1) + 2, 2);
    auto overBC = nCr(n - 2 * (limit + 1) + 2, 2);

    auto overABC = nCr(n - 3 * (limit + 1) + 2, 2);

    return total - (overA + overB + overC) + (overAB + overAC + overBC) - overABC;
    }
};
