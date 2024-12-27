








/*233. Number of Digit One
Attempted
Hard
Topics
Companies
Hint
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
 

*/
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

class Solution {
public:
    int countDigitOne(unsigned int n) {
        int p = 0; // Counter for digit '1'

    for (int k = 1; k <= n; k++) {
        int num = k; // Temporary variable to process the digits of the number
        while (num > 0) {
            if (num % 10 == 1) { // Check if the last digit is '1'
                p++;
            }
            num /= 10; // Remove the last digit
        }
    }

    return p; // Return the count of digit '1'
}
};
