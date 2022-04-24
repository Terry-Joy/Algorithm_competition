#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=5005;
ll dp[maxn][maxn];//dp[i][j]自己上一次选的是第i小的数,别人刚选的是j
int n,a[maxn],cnt[maxn],pos[maxn],inv[maxn];
ll sum[maxn];
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]]=i,inv[i]=mypow(i,mod-2);
    for(int i=n;i>=1;--i){//i小 
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        for(int j=i+1;j<=n;++j){ 
            cnt[pos[j]]++;
            sum[pos[j]]+=dp[i][j];
            sum[pos[j]]%=mod;
        }
        for(int j=n-1;j>=0;--j)sum[j]=(sum[j]+sum[j+1])%mod;
        for(int j=n-1;j>=0;--j)cnt[j]=(cnt[j]+cnt[j+1])%mod;
        for(int j=0;j<i;++j){//i变为刚选的 
            if(cnt[pos[j]])dp[j][i]=(dp[j][i]+1ll*sum[pos[j]]*inv[cnt[pos[j]]]%mod+1)%mod;
        }

    }
    ll ans=0;
    for(int i=1;i<=n;++i)ans=(ans+dp[0][i])%mod;
    ans=(ans*inv[n]%mod+1)%mod;
    cout<<ans;
    return 0;
}
