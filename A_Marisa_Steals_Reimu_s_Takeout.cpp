#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> w(n);
    for(int &x:w)cin>>x;
    sort(w.begin(),w.end());
    vector<int> pref;
    pref.push_back(w[0]);
    for(int i=0;i<n;i++){
        if(pref.back()%3!=0)
        pref.back()+=w[i];
        else pref.push_back(w[i]);
    }
    cout<<pref.size()-1<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){solve();}
}