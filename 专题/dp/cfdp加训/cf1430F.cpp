#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
typedef long long ll;
ll dp[maxn];//前i个做完，第i个做完换了
int l[maxn],r[maxn],a[maxn],k,n;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d%d%d",&l[i],&r[i],&a[i]),dp[i]=1e18;
    dp[0]=0;
    for(int i=0;i<n;++i){
        ll ans=dp[i],num=k;
        for(int j=i+1;j<=n;++j){
            ll time=(max(0ll,(a[j]-num))+k-1)/k;
            if(l[j]+time>r[j])break;
            ll cost=num+time*k-a[j];
            ans+=a[j];
            if(j==n)dp[j]=min(dp[j],ans);
            else if(l[j]+time<l[j+1])//不更新这个状态
                dp[j]=min(dp[j],ans+cost);
            num=cost;
        }
    }
    cout<<(dp[n]==1e18?-1:dp[n])<<"\n";
    return 0;
}