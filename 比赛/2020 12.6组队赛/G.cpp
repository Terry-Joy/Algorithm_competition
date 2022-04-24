#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int>P;
P a[4],b[4];
const int del=500;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i].fi>>a[i].se;
        for(int i=1;i<=n;++i)cin>>b[i].fi>>b[i].se;
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(int i=1;i<=n;++i){ 
            cout<<6<<endl;
            cout<<a[i].fi<<" "<<a[i].se<<endl;
            cout<<a[i].fi<<" "<<i+del<<endl;
            cout<<-i-del<<" "<<i+del<<endl;
            cout<<-i-del<<" "<<-i-del<<endl;
            cout<<b[i].fi<<" "<<-i-del<<endl;
            cout<<b[i].fi<<" "<<b[i].se<<endl;
        }
    }
    return 0;
}
