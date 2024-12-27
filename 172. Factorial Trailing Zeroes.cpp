/* 172.Factorial Trailing Zeroes Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104
 

Follow up: Could you write a solution that works in logarithmic time complexity?*/
















class Solution {
public:
    int trailingZeroes(int n) {
        int q = 0; // Initialize trailing zero count
    int z = 5; // Start with the smallest power of 5
    
    while (n >= z) {
        q += n / z; // Add multiples of the current power of 5
        z *= 5;     // Move to the next power of 5
    }
        return q;
    }
};
