
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int wttime=0,time=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size();i++){
            wttime+=time;
            time+=bt[i];
        }
        return(wttime/bt.size());
        
    }
};
