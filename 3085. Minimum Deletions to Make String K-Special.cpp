class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> freq(26);
        for(auto c : word){
            freq[c-'a']++;
        }
        int mx = 0;
        for(auto x : freq){
            mx = max(mx,x);
        }
        int ans = n;
        // int ur = k/2, lr = k - k/2;
        for(int L : freq){
            int del = 0;
            for(int i=0;i<26;i++){
                //go thru all characters to find which lies within window
                if(freq[i]< L){
                    del += freq[i]; // deleteing the whole bar
                }
                else if(freq[i] > L + k){
                    del += (freq[i] - L - k);
                }
            }
            ans = min(ans, del);
        }
        return ans;
    }
};
