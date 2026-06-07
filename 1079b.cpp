#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

const int inf = 1e9;
const long long INF = 1e18;

bool isprime(long long n){
    for(long long i=2;i*i<=n;i++){ if(n%i==0) return false; }
    return true;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

long long popcount(long long n) {
    long long cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

long long reverse_digits(long long n) {
    long long r = 0;
    while (n) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

long long digit_sum(long long n) {
    long long s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    vector<int> L(n + 1, n), R(n + 1, -1);
    for (int i = 0; i < n; i++) {
        L[a[i]] = min(L[a[i]], i);
        R[a[i]] = max(R[a[i]], i);
    }

    for (int x = 1; x <= n; x++) {
        if (R[x] == -1) continue; // x not in a
        if (pos[x] < L[x] || pos[x] > R[x]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}