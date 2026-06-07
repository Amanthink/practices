#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
        int left=0,right=n-1;
        bool flag=true;
        for(auto it:mp){
            if(it.second%2!=0){flag=false;break;}
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
       }
    }
