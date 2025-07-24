

class Solution {
public:
    string toBase(int n, int b) {
        string result = "";
        while (n > 0) {
            result += to_string(n % b);
            n /= b;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; ++base) {
            string baseRep = toBase(n, base);
            if (!isPalindrome(baseRep)) return false;
        }
        return true;
    }
};
