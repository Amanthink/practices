class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // base case
        vector<int> result;

        for (int coin = 1; coin <= n; ++coin) {
            vector<int> newDp = dp;

            // Simulate adding this coin to dp
            for (int i = coin; i <= n; ++i) {
                newDp[i] += newDp[i - coin];
            }

            bool isValid = true;
            for (int i = 1; i <= n; ++i) {
                if (newDp[i] > numWays[i - 1]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                dp = newDp;
                result.push_back(coin);
            }
        }

        // Final check
        for (int i = 1; i <= n; ++i) {
            if (dp[i] != numWays[i - 1]) return {};
        }

        return result;
    }
};
