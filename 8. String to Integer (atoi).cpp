class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int r = 0;
        bool neg = false;

        // Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            neg = (s[i] == '-');
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (r > (INT_MAX - digit) / 10)
                return neg ? INT_MIN : INT_MAX;

            r = r * 10 + digit;
            i++;
        }

        return neg ? -r : r;
    }
};
