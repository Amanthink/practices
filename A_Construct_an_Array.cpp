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

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long L = 1;
        long long R = (long long)1e18;

        bool ok = true;

        for (int i = 0; i < n - 1; i++) {

            if (a[i] > a[i + 1]) {

                // adjacent inversions impossible
                if (i > 0 && a[i - 1] > a[i]) {
                    ok = false;
                }

                L = max(L, a[i] - a[i + 1]);

            } else {

                R = min(R, a[i + 1] - a[i]);
            }
        }

        cout << (ok && L <= R ? "Yes" : "No") << '\n';
    }

    return 0;
}