class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        
        if (n <= 0)
            return false; 
        
        double logarithmBase4 = log(n) / log(4);
                return (logarithmBase4 == (int)logarithmBase4);
    }
};
