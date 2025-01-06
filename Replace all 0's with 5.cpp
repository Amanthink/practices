class Solution {
public:
    int convertFive(int n) {
        // If n is 0, directly return 5
        if (n == 0) return 5;
        
        int result = 0;
        int place = 1;

        // Process each digit and replace 0 with 5
        while (n > 0) {
            int remainder = n % 10;
            if (remainder == 0) {
                remainder = 5;
            }
            result = result + remainder * place;
            place *= 10;
            n /= 10;
        }
        
        return result;
    }
};
