class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // Helper function to check if a number contains digit '0'
        auto containsZero = [](int num) {
            while (num > 0) {
                if (num % 10 == 0) return true;
                num /= 10;
            }
            return false;
        };

        // Iterate to find the first valid pair
        for (int i = 1; i < n; i++) {
            int complement = n - i;
            if (!containsZero(i) && !containsZero(complement)) {
                return {i, complement};
            }
        }

        return {}; // This point is never reached due to constraints
    }
};
