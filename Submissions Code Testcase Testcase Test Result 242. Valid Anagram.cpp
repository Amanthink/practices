class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[256],hash2[256];
        if(s.size()!=t.size())
        return false;
        else{
        for(int i=0;i<s.size();i++){
                hash1[s[i]]++;
                hash2[t[i]]++;
                
            }
        }
        int i=0;
        while(i<256){
        if(hash1[i]!=hash2[i])
                return false;
                i++;}
        return true;
        
    }
};
