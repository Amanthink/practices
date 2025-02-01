class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);  
        int j = 0;  

        for (int i = 0; i < n && j < n; i++, j++) {
            temp[j] = arr[i]; 
            if (arr[i] == 0 && j + 1 < n) { 
                j++;
                temp[j] = 0;
            }
        }

        arr = temp; 
    }
};
