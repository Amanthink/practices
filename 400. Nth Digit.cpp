class Solution {
public:
    int findNthDigit(int n) {
        // `len` is the length of the current group of numbers (1-digit, 2-digit, etc.)
        // `count` is the number of numbers in that group
        // `start` is the first number in the current group
        long long len = 1, count = 9, start = 1;

        // Step 1: Find the length `len` of the number that contains the n-th digit
        // Keep reducing n until it falls within the current group
        while (n > len * count) {
            n -= len * count;    // Skip over all digits in the current group
            len++;               // Move to the next group (2-digit, 3-digit, etc.)
            count *= 10;         // Update the number count (90, 900, etc.)
            start *= 10;         // Update the starting number (10, 100, etc.)
        }

        // Step 2: Find the actual number that contains the n-th digit
        // (n-1)/len gives how many full numbers we pass before the target digit
        start += (n - 1) / len;

        // Step 3: Convert the number to a string so we can access individual digits
        string num = to_string(start);

        // Step 4: Get the exact digit from the number
        // (n-1) % len gives the index of the digit within the number
        return num[(n - 1) % len] - '0';  // Convert char digit to int
    }
};
