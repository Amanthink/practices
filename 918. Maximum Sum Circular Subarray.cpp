class Solution {
public:
    int normalKadane(vector<int>& arr) {
        int maxNormalSum = arr[0], currentMax = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            currentMax = max(currentMax + arr[i], arr[i]);
            maxNormalSum = max(maxNormalSum, currentMax);
        }
        return maxNormalSum;
    }

    int maxSubarraySumCircular(vector<int>& arr) {
        int maxNormalSum = normalKadane(arr); 
        if (maxNormalSum < 0) {
            return maxNormalSum;
        }

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
            arr[i] = -arr[i];
        }

        int maxInvertedSum = normalKadane(arr); 
        int maxCircularSum = totalSum + maxInvertedSum; 

        
        return max(maxNormalSum, maxCircularSum);
    }
};
