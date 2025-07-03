class Solution {
public:
  int nthUglyNumber(int n) {
    static vector<int> ugly;
    long long a, b, c, m = INT_MAX;
    if (ugly.empty()) {
        for (a=1; a<=m; a*=2)
            for (b=a; b<=m; b*=3)
                for (c=b; c<=m; c*=5)
                    ugly.push_back(c);
        sort(begin(ugly), end(ugly));
    }
    return ugly[n-1];
}
};
