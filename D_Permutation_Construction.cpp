#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<long long,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end()); 

        vector<int> p(n);
        for(int i=0;i<n;i++){
            p[v[i].second] = i+1;
        }

        for(int x : p) cout << x << " ";
        cout << "\n";
    }
}