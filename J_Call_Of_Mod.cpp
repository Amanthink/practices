#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
   
    vector<bool> used(n + 1, false);
    vector<pair<int,int>> pairs;
    
    for (int i = 1; i <= n; i++) {
        int j = 2 * i;
        if (j <= n && !used[i] && !used[j]) {
            pairs.push_back({i, j});
            used[i] = true;
            used[j] = true;
        }
    }
    
    int max_k = 1 + (int)pairs.size();
    
    if (k > max_k) {
        cout << -1 << "\n";
        return;
    }
    
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0); // p[i] = i
  
    for (int idx = 0; idx < k - 1; idx++) {
        auto [i, j] = pairs[idx];
        swap(p[i], p[j]);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}