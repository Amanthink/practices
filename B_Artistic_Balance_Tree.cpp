#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<int> x(m);
        unordered_set<int> s;

        for (int i = 0; i < m; i++) {
            cin >> x[i];
            s.insert(x[i]); 
        }

        int k = s.size();

        sort(a.begin(), a.end(), greater<long long>());

        long long total = 0;
        for (auto v : a) total += v;

        long long marked = 0;
        for (int i = 0; i < k && i < n; i++) {
            marked += a[i];
        }

        cout << total - marked << "\n";
    }

    return 0;
}