
class Solution{
    public:
    //Function to find median of the array elements.
    int median(int arr[],int N)
    {
        
        sort(arr,arr+N);
        
        //your code here
        //If median is in fraction then convert it to integer and return
        if(N%2!=0)
        return arr[N/2];
        return (arr[(N/2)-1]+arr[N/2])/2;
    }
    //Function to find mean of the array elements.
    int mean(int arr[],int N)
    {
        //your code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        return sum/=N;
    }
};
