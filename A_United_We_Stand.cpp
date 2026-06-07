#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
       int m=*max_element(a.begin(),a.end());
       vector<long long> b,c;
         for(int i=0;i<n;i++)
         {
              if(a[i]==m)
                c.push_back(a[i]);
              else
                b.push_back(a[i]);
         }
         if(b.size()==0)
         {
             cout<<"-1\n";
             continue;
         }
         else {
            cout<<b.size()<<" "<<c.size()<<"\n";
            for(int i=0;i<b.size();i++)                cout<<b[i]<<" ";
            cout<<"\n";
            for(int i=0;i<c.size();i++)                cout<<c[i]<<" ";
            cout<<"\n";     
            
         }
    }
    return 0;
}