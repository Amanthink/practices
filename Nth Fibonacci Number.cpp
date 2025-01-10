class Solution {
public:
    int nthFibonacci(int n) {
        if(n==0)
        return 0;
        if (n == 1 || n == 2) return 1;
        
        int a = 1, b = 1;
        for (int i = 3; i <= n; ++i) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};
