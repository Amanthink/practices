class Solution {
public:
    int numberOfSteps(int n) {

        int count=0;
        while(n>0){
            if(n%2==0)
            n/=2;
            else{
                n-=1;
            }
            count++;
        }
        return count;
    }
};
or



|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    class Solution {
public:
    int numberOfSteps(int n) {
        return n == 0 ? 0 : 1 + numberOfSteps(n % 2 == 0 ? n / 2 : n - 1);
    }
};

