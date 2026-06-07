#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 count_cells(int64 n, int64 k) {
    int64 m = (2 * n) / k;
    int64 m1 = (n + 1) / k;

    int64 part1 = k * m1 * (m1 + 1) / 2 - m1;

    int64 total = k * m * (m + 1) / 2;
    int64 sum1 = k * m1 * (m1 + 1) / 2;

    int64 part2 = (m - m1) * (2 * n + 1) - (total - sum1);

    return part1 + part2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int64 n, k1, k2;
        cin >> n >> k1 >> k2;

        int64 A = count_cells(n, k1);
        int64 B = count_cells(n, k2);

        int64 l = lcm(k1, k2);
        int64 C = count_cells(n, l);

        int64 alice = A;
        int64 bob = B - C;

        if (alice > bob) cout << "Alice\n";
        else if (bob > alice) cout << "Bob\n";
        else cout << "Tie\n";
    }
}