class Solution {
public:
    // Converts number into its digits (in correct order)
    void digis(int num, vector<int>& digits) {
        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Checks if the number is self-dividing
    bool div(int num, vector<int>& digits) {
        for (int c = 0; c < digits.size(); c++) {
            if (digits[c] == 0 || num % digits[c] != 0) return false;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            vector<int> digits;
            digis(i, digits);
            if (div(i, digits)) ans.push_back(i);
        }
        return ans;
    }
};
