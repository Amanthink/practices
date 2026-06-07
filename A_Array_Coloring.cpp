#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;   
        vector<int> a(n); 
        int sum=0;  
        for (size_t i = 0; i < n; i++)
        {
                cin>>a[i];
                sum+=a[i];  
        }
        int left=0;
        bool flag=false;
        for(int i=0;i<n-1;i++){
            sum-=a[i];  
            left+=a[i];
            if(sum%2==0&&left%2==0){
                flag=true;

                break;
            }
            else if(sum%2==1&&left%2==1){
                flag=true;
                break;
            }
        }

        if(!flag){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        
    }
}