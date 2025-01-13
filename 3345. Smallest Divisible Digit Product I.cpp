class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int num = n, product = 1;
            
            // Calculate the product of digits
            while (num > 0) {
                int digit = num % 10; // Get the last digit
                 // Ignore zeros
                    product *= digit;
                
                num /= 10; // Remove the last digit
            }
            
            // Check if the product is divisible by t
            if (product % t == 0) {
                return n;
            }
            
            n++; // Increment to check the next number
        }
        return 0;
    }
};
