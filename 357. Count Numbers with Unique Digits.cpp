class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;

        
        int res = 10;

        int uniqueDigits = 9;  
        int available = 9;     

        while(n > 1 && available > 0) {
            uniqueDigits *= available; 
            res += uniqueDigits;      
            available--;  
            n--;             
        }

        return res;
    }
};
