class Solution {
public:
    int maxPower(string s) {
        int curr=1,res=1;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                curr=1;
            }
            else{
                curr++;
                res=max(res,curr);
            }
        }
        return res;
    }
};
