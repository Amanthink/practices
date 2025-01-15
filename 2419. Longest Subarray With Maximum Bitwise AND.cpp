class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int maxVal = *max_element(arr.begin(), arr.end()); 
        int maxLength = 0, currentLength = 0;

        for (int num : arr) {
            if (num == maxVal) {
                currentLength++; 
                maxLength = max(maxLength, currentLength); 
            } else {
                currentLength = 0; 
            }
        }

        return maxLength;
    }
};
