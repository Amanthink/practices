class Solution {
  public:
    int digitalRoot(int n) {
        while (n >= 10) { // Continue until the number becomes a single digit
            int sum = 0;
            while (n > 0) { // Calculate the sum of digits
                sum += n % 10;
                n /= 10;
            }
            n = sum; // Update n to the calculated sum
        }
        return n; // Single-digit result
    }
};



