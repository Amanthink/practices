















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
