class Solution {
  public:
 
    int maxIndexDiff(vector<int>& arr) {
     int n = arr.size();
     if(n<2)
     return 0;
        int maxDiff = -1;

        for (int start = 0; start < n; start++) { 
            for (int end = n - 1; end > start; end--) {\
                if (arr[start] <= arr[end]) { 
                    maxDiff = max(maxDiff, end - start);
                    break;
                }
            }
        }
        return maxDiff;
        
    }
};
