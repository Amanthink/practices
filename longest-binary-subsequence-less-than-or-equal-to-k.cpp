class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        int power = 0;
        long long value = 0;

        // Traverse from right to left (lowest to highest bit)
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                // Always include zeros
                count++;
            } else {
                // Try including '1' only if within k's limit
                if (power < 31) { // Prevent overflow for 2^power
                    long long temp = value + (1LL << power);
                    if (temp <= k) {
                        value = temp;
                        count++;
                    }
                }
            }
            power++;
        }
        return count;
    }
};
