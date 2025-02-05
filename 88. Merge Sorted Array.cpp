#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Use vector instead of variable-length array
        vector<int> temp(nums1.begin(), nums1.begin() + m);

        int i = 0, j = 0, k = 0;

        // Merge temp and nums2 back into nums1
        while (i < m && j < n) {
            if (temp[i] <= nums2[j]) {
                nums1[k++] = temp[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        // Copy any remaining elements from temp
        while (i < m) {
            nums1[k++] = temp[i++];
        }

        // Copy any remaining elements from nums2
        while (j < n) {
            nums1[k++] = nums2[j++];
        }
    }
};
