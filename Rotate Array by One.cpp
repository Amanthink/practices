
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
       vector<int> ans(arr.size());
       for(int i=0;i<arr.size();i++){
           if(i<ans.size()-1){
               ans[i+1]=arr[i];
           }
           else{
               ans[0]=arr[arr.size()-1];
           }
       }
       arr=ans;
    }
};
