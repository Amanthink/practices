int getlargest(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = i; j < n; ++j) {
            if (arr[j] > arr[i]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            return arr[i];
        }
    }

    return -1;
}
            
