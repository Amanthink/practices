class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        int E=0,W=0,N=0,S=0;
        for(int i=0;i<n;i++){
            if(s[i]=='E') E++;
            else if (s[i]=='W') W++;
            else if (s[i]=='N') N++;
            else S++;
            ans = max(ans, min(abs(N-S) + abs(E-W) + 2*k, i+1));
        }
        return ans;
    }
};
