class Solution {
public:
    int mySqrt(int x) {
          if (x == 0 || x == 1) return x;

    int low = 1, high = x, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow using division
        if (mid <= x / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
    }
};
