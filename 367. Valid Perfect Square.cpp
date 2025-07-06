class Solution {
public:
    bool isPerfectSquare(int num) {
        int r = sqrt(num);
        return r * r == num;
    }
};
