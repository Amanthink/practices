#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i]; 
       sort(a.begin(),a.end());

    while(a.size()!=1){
        int p=floor((a[0]+a[1])/2);
        a.erase(a.begin());
        a.erase(a.begin());
        a.push_back(p);
        if(a.size()==1)break;
        else sort(a.begin(),a.end());
    }
    cout<<a[0]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}