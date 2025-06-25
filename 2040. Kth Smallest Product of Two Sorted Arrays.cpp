class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // Separate nums1 into negatives (A1) and non-negatives (A2)
        vector<long long> A1, A2, B1, B2;
        for(int x : nums1) {
            if (x < 0) A1.push_back(-1LL * x);
            else       A2.push_back( 1LL * x);
        }
        for(int x : nums2) {
            if (x < 0) B1.push_back(-1LL * x);
            else       B2.push_back( 1LL * x);
        }
        // Sort absolute-values ascending
        sort(A1.begin(), A1.end());
        sort(B1.begin(), B1.end());
        sort(A2.begin(), A2.end());
        sort(B2.begin(), B2.end());
        
        // Count of negative products: A_neg * B_pos + A_pos * B_neg (zero not counted here)
        long long negCount = (long long)A1.size() * (long long)B2.size()
                           + (long long)A2.size() * (long long)B1.size();
        
        int sign = 1;
        if (k <= negCount) {
            // k-th smallest is negative
            sign = -1;
            // We find (negCount - k + 1)-th smallest by absolute value
            k = negCount - k + 1;
            // Swap B1 and B2 lists so that both parts become positive for counting
            swap(B1, B2);
        } else {
            // k-th smallest is non-negative (zero or positive)
            k -= negCount;
        }
        
        // Binary search on m = product value (absolute)
        long long lo = 0, hi = 10000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            // Count how many products <= mid
            long long cnt = countNoGreater(A1, B1, mid)
                          + countNoGreater(A2, B2, mid);
            if (cnt >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return sign * lo;
    }
    
private:
    // Count pairs (a, b) with a from A and b from B such that a*b <= m.
    // Assumes A and B are sorted ascending and all entries >= 0.
    long long countNoGreater(const vector<long long>& A, const vector<long long>& B, long long m) {
        long long count = 0;
        int j = (int)B.size() - 1;
        for (long long a : A) {
            while (j >= 0 && a * B[j] > m) {
                --j;
            }
            count += (j + 1);
            if (j < 0) break;
        }
        return count;
    }
};
