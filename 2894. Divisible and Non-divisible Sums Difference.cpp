class Solution {
public:
    int differenceOfSums(int n, int m) {
        int notDiv = 0, div = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) div += i;
            else notDiv += i;
        }
        return notDiv - div;
    }
};
