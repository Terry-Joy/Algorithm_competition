#include<bits/stdc++.h>

using namespace std;
const int maxn=100005;
int t,n,a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int mx=a[1],ans=-1e9;
        for(int i=2;i<=n;++i){ 
            ans=max(ans,mx-a[i]);
            mx=max(mx,a[i]);
        }
        cout<<ans<<"\n";
   } 
    return 0;
}
