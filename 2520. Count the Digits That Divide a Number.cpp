class Solution {
public:
    int countDigits(int num) {
        vector<int> ans;
        int n=num;
        while(n!=NULL){
            ans.push_back(n%10);
            n/=10;
        } 
        int count=0;
        n=0;
        while(n<ans.size()){
            if(num%ans[n]==0) count++;
            n++;
           
        }
        return count;
    }
};
