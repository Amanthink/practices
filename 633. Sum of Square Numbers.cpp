/*633. Sum of Square Numbers*/
class Solution {
public:
    bool judgeSquareSum(int c) {
         if (c < 0) {
            return false;  
        }
        
        for (long long int i = 0; i * i <= c; i++) {  
            long long int j = c - i * i; 
            int sqrt_j = sqrt(j);  
            if (sqrt_j * sqrt_j == j) {  
                return true;  
            }
        }
        
        return false;
        
    }
};
