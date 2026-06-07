#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(101, 0);
        bool bad = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            if (freq[a[i]] > 1) bad = true;
        }

        if (bad) {
            cout << -1 << '\n';
        } else {
            sort(a.rbegin(), a.rend());
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}