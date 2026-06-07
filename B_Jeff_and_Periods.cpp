#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

const int inf = 1e9;
const long long INF = 1e18;


pair<bool,int> checkap(vector<int>a){
    if(a.size()==1)return {true,0};
    else {
        int d=a[1]-a[0];
        for(int i=2;i<a.size();i++){
            int temp=a[i]-a[i-1];
        if(temp!=d)return {false,INT_MAX} ;     
        }
        return{true,d};
    }
}

void solve(){
    
 int n;cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){cin>>a[i];}
unordered_map<int,vector<int>>mp;
for(int i=0;i<n;i++){
    mp[a[i]].push_back(i);
}
int c=0;
vector<pair<int,int>> ans;
for(auto &p:mp){
if(checkap(p.second).first){c++;
    ans.push_back({p.first, checkap(p.second).second});
}
    }
    sort(ans.begin(),ans.end());
    cout<<c<<endl;
for(auto&p:ans){
    cout<<p.first<<" "<<p.second<<endl;
}
}


 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}