class Solution {
public:
    int inSequence(int a, int b, int c) {
        // Check if both a and b are divisible by c
        if (c != 0 && b >= a && (b - a) % c == 0) {
            return 1;  // Return 1 if b is in the sequence starting from a with step size c
        }
        return 0;  // Return 0 otherwise
    }
};

