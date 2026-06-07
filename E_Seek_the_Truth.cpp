#include <bits/stdc++.h>
using namespace std;


int ask_insert(int x) {
    cout << "I " << x << endl;
    cout.flush();

    int response;
    cin >> response;

    if (response == -1) exit(0); 
    return response;
}

int ask_query(int y) {
    cout << "Q " << y << endl;
    cout.flush();

    int response;
    cin >> response;

    if (response == -1) exit(0);
    return response;
}

void answer(int k, int c) {
    cout << "A " << k << " " << c << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a = 0;
        cout << a << endl;
        cout.flush();

        vector<int> vals;
        for (int i = 0; i < n; i++) {
            int x = (1 << i);
            int sz = ask_insert(x);
            vals.push_back(sz);
        }

        int final_size = ask_query(0);

        int k;

        if (final_size == n + 1) {
            k = 3; // XOR
        } else {
            // heuristic split
            // you can refine if needed
            if (vals.back() == vals[0]) {
                k = 1; // AND
            } else {
                k = 2; // OR
            }
        }

        // ----------- STEP 4: Find c -----------
        int c = 0;

        if (k == 2 || k == 3) {
            // f(0) = c
            ask_insert(0);

            // find c via binary lifting
            for (int i = n - 1; i >= 0; i--) {
                int y = (1 << i);
                int cnt = ask_query(y);

                if (cnt > 0) {
                    c |= y;
                }
            }

        } else {
            // k == 1 (AND)
            for (int i = 0; i < n; i++) {
                int y = (1 << i);
                int cnt = ask_query(y);

                if (cnt > 0) {
                    c |= y;
                }
            }
        }

        // ----------- STEP 5: Output answer -----------
        answer(k, c);
    }

    return 0;
}