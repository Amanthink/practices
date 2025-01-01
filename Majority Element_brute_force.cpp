


// brute force
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++){
            int freq=0;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    freq++;
                }
            }
            if(freq>=arr.size()/2){
                return arr[i];
            }
        }
        return -1;
        // your code here
    }
};
