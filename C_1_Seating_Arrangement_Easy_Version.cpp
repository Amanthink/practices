#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,s;
    cin>>n>>x>>s;
    string a;
   cin>>a;
    int total_no_of_seats=x*s;
    int count=0;
    int temp=s;
  while(total_no_of_seats--&&a.size()>0){
     while(s--){
        if(s!=0&&count%s==0){
            count++;
            a.erase(a.begin());
            cout<<"i am reached here"<<endl;
        }
        else {
            if(a.front()!='I'){count++;a.erase(a.begin());}
            else a.erase(a.begin());
            cout<<"i am reached here twice "<<endl;
        }
     }
    s=temp;
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}