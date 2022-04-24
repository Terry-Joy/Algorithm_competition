#include<bits/stdc++.h>

using namespace std;
const int maxn=505;
int t,n,a[maxn],sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i],sum[i]=a[i]-a[i-1]-1;
        int ans=0;
        for(int i=2;i<=n;++i)ans+=sum[i];
        cout<<ans-min(sum[2],sum[n])<<"\n";
    }
    return 0;
}