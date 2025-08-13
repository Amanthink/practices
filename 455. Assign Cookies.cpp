class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int m = g.size(), n = s.size();
        int left = 0, right = 0;
        int ans = 0;

        while (left < m && right < n) {
            if (s[right] >= g[left]) { 
                ans++;
                left++;
            }
            right++;
        }

        return ans;
    }
};
