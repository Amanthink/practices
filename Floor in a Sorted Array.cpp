int findFloor(vector<int>& arr, int k) {
    int p = -1; 
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= k) {  
            p = i;  
        }
    }

    return p;  
}
