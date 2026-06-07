#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // keeping the pre sum and minimum element to chose minimum element
        long long pref = 0;
        long long mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            pref += a[i];                 // keeping the prefix array
            mn = min(mn, pref / (i + 1)); // choosing minimum out of the minimum value in past and the current frosted value must be less then i+1*height

            cout << mn;
            if (i + 1 < n)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}