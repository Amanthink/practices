class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<long, long> findRepeating(long *arr, int n){
        //code here
        pair<long long int,long long int> ans(-1,-1);
        int count=0,p=0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                p=arr[i];
                count++;
            }
            if(p>0){
            ans.first=p;
            ans.second=count+1;
            }
        }
        return ans;
    }
};
