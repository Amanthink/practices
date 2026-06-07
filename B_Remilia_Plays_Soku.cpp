#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;

    long long d = abs(x1 - x2);
    d = min(d, n - d);

    if (d == n / 2) {
        cout << d << "\n";
    } else {
        cout << d + k << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}