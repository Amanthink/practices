#include<bits/stdc++.h>
using namespace std;    
int main(){
    int t;cin>>t;
    while(t--){
       int x,k;cin>>x>>k;
       if(x%2==0)       {
           if(k%2==0)
           {
               cout<<"2"<<endl;
               cout<<x-1<<" "<<"1"<<endl;
               goto next;
           }
           else
           {
               cout<<"1"<<endl;
               cout<<x<<endl;
                goto next;  
           }
       }
       else
       {
            if(k%2!=0)
           {
               cout<<"2"<<endl;
               cout<<x-1<<" "<<"1"<<endl;
               goto next;   
           }
           else
           {
               cout<<"1"<<endl;
               cout<<x<<endl;
               goto next;
           }
       }
         next:;
    }
}