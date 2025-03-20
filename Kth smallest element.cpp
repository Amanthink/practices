class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int N, int k)
    {
        // Your code here
        if(k-1>N) return -1;
        sort(arr,arr+N);
        return arr[k-1];
    }
};

