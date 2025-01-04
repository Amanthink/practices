class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        for(int i=0;i<s.length();i++){
            if(i>=s.length())
            return true;
            else{
                if(s[i]!=s[s.length()-i-1])
                return false;
            }
        }
        return true;
    }
};
