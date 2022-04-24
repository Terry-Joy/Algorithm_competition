#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int maxn=2005;
const int mod=1e9+7;
ll dp[maxn][maxn];
int inv[maxn],n,a[maxn];
struct Bit{ 
    ll c[maxn];
    void add(int x,int val){ 
        while(x<=n+1){ 
            c[x]+=val;
            if(c[x]>=mod)c[x]-=mod;
            x+=lowbit(x);
        }
    }
    ll ask(int x){ 
        ll ans=0;
        while(x){ 
            ans+=c[x];
            if(ans>=mod)ans-=mod;
            x-=lowbit(x);
        }
        return ans;
    }
}f[3][maxn];//k、dp[i][*],dp[*][j];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv[1]=1;
    for(int i=2;i<maxn;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    cin>>n;
    for(int i=2;i<=n+1;++i)cin>>a[i];
    a[1]=0;a[n+2]=n+1;
    for(int i=1;i<=n+2;++i)dp[i][i]=1;
    for(int len=2;len<=n+2;++len){ 
        for(int l=1;l+len-1<=n+2;++l){ 
            int r=l+len-1;
            if(a[l]>=a[r])continue;
            int k=f[0][l].ask(a[r]);
            if(k){ 
                dp[l][r]=(1+1ll*(f[1][l].ask(a[r])+f[2][r].ask(n+1-a[l]))*inv[k]%mod)%mod;
            }
            f[0][l].add(a[r],1);
            f[1][l].add(a[r],dp[l][r]);
            f[2][r].add(n+1-a[l],dp[l][r]);
        }
    }
    cout<<dp[1][n+2];
    return 0;
}
