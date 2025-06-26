class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers can't be palindromes

        int original = x;
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev == original;
    }
};
