#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,t;
ll mn[2],cnt[2],sum[2],a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=0;i<=1;++i){
            mn[i]=2e9;cnt[i]=sum[i]=0;
        }
        ll ans=2e9*n;
        for(int i=1;i<=n;++i){
            int x=(i-1)&1;
            ++cnt[x];
            mn[x]=min(mn[x],a[i]);
            sum[x]+=a[i];
            if(i!=1)
                ans=min(ans,sum[0]+(n-cnt[0])*mn[0]+sum[1]+(n-cnt[1])*mn[1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}