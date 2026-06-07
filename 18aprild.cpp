#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool can(vector<int>& a, int n, int k, int x) {
    int count = 1;
    int cur_or = a[0];
    int cur_and = a[0];

    for (int i = 1; i < n; i++) {
        int new_or = cur_or | a[i];
        int new_and = cur_and & a[i];

        if ((new_or ^ new_and) > x) {
            count++;
            cur_or = a[i];
            cur_and = a[i];
        } else {
            cur_or = new_or;
            cur_and = new_and;
        }
    }

    return count <= k;
}

int solve(vector<int>& a, int n, int k) {
    int low = 0, high = (1 << 18), ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (can(a, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << solve(a, n, k) << "\n";
    }
}