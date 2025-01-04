class Solution {
public:
    bool isAnagram(string s, string t) {
      int n=s.length(),m=t.length();
      if(s!=t)
      return false;
      else{
        for(int i=0;i<n;i++){
            if(s[i]!=t[n-i-1])
            return false;
        }
      }
      return true;
       
    }
};
