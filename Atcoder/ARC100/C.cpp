#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int a[maxn],n;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]-=i;
    sort(a+1,a+1+n);
    int pos=(n+1)/2;
    ll ans=0;
    for(int i=1;i<=n;++i)ans+=abs(a[i]-a[pos]);
    cout<<ans<<"\n";
    return 0;
}
