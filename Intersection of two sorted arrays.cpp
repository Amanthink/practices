class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        vector<int> ans;
        int i = 0, j = 0;
        int m = arr1.size(), n = arr2.size();
        
        while (i < m && j < n) {
            if (arr1[i] == arr2[j]) {
                // Avoid adding duplicates if already present in ans
                if (ans.empty() || ans.back() != arr1[i]) 
                    ans.push_back(arr1[i]);

                i++; j++;  // Move both pointers forward
            } 
            else if (arr1[i] < arr2[j]) 
                i++;
            else 
                j++;
        }
        
        return ans;
    }
};
