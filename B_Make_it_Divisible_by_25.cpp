#include <bits/stdc++.h>
using namespace std;

int solve(string s, string target) {
    int n = s.size();
    int cnt = 0;
    
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == target[1]) break;
        cnt++;
    }
    if (i < 0) return 1e9;

    for (int j = i - 1; j >= 0; j--) {
        if (s[j] == target[0]) return cnt + (i - j - 1);
    }
    return 1e9;
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int ans = min({
            solve(s, "00"),
            solve(s, "25"),
            solve(s, "50"),
            solve(s, "75")
        });

        cout << ans << endl;
    }
}