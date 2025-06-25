class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> products;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                products.push_back(1LL * nums1[i] * nums2[j]);  // Ensure long long
            }
        }
        sort(products.begin(), products.end());
        return products[k - 1];  // 0-based indexing
    }
};
