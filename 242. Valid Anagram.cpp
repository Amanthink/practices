class Solution {
public:
    bool isAnagram(string s, string t) {
   unordered_map<char,int> a,b;
   for(char c:s) a[c]++;
   for(char c:t) b[c]++;
   for(int p=97;p<129;p++){
    if(a[(char)p]!=b[(char)p]) return false;
   }
   return true;
    }
};
