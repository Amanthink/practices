#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<long long> s;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s.insert(x);
    }

    cout << (int)s.size() - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}