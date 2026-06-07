#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        long long mn = 1LL * k * (k + 1) / 2;

        long long mx =
            1LL * n * (n + 1) / 2
            - 1LL * (n - k) * (n - k + 1) / 2;

        if(x >= mn && x <= mx)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}