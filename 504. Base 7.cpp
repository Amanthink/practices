class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool isNegative = num < 0;
        num = abs(num);

        string res = "";
        while (num > 0) {
            res = to_string(num % 7) + res;
            num /= 7;
        }

        if (isNegative) res = "-" + res;

        return res;
    }
};
