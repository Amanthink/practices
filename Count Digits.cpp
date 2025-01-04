class Solution {
public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int k = n, count = 0;

        // Process each digit of the number
        while (k > 0) {
            int digit = k % 10; // Extract the last digit
            if (digit != 0 && n % digit == 0) { // Check if the digit divides n
                count++;
            }
            k = k / 10; // Remove the last digit
        }

        return count;
    }
};
