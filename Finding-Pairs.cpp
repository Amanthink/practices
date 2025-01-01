class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
    int i=0,j=arr.size()-1;
    sort(arr.begin(),arr.end());
    while(i<j){
        int pair_sum=arr[i]+arr[j];
        if(pair_sum>target){
            j--;
        }
        else if(pair_sum<target){
            i++;
        }
        else{
            return(true);
        }
    }
    return false;
    }
    };
