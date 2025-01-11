void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d >= n

    // Step 1: Store the first d elements in a temporary array
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift the remaining elements to the left by d positions
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Step 3: Copy the elements from temp to the end of the array
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}
