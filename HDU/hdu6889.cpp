#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=2e5+5;
ll prime[maxn],g1[maxm],w[maxm],sum[maxn],n,mod;
int cnt,m,id1[maxn],id2[maxn];
bool v[maxn];
void init(int x){ 
    v[1]=1;
    for(int i=2;i<=x;++i){ 
        if(!v[i])prime[++cnt]=i,sum[cnt]=(sum[cnt-1]+i)%mod;
        for(int j=1;j<=cnt&&prime[j]*i<=x;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        m=cnt=0;
        scanf("%lld%lld",&n,&mod);
        n++;
        int sqr=sqrt(n);
        init(sqr);
        for(ll i=1,j;i<=n;i=j+1){ 
            j=n/(n/i);
            w[++m]=n/i;
            g1[m]=w[m]%mod;
            g1[m]=g1[m]*(g1[m]+1)%mod*((mod+1)/2)%mod-1;
            if(w[m]<=sqr)id1[w[m]]=m;
            else id2[j]=m;
        }
        for(int i=1;i<=cnt;++i){ 
            ll pr=prime[i]*prime[i];
            for(int j=1;j<=m&&pr<=w[j];++j){ 
                ll x=w[j]/prime[i];
                x=((x<=sqr)?id1[x]:id2[n/x]);
                g1[j]=(g1[j]-prime[i]*(g1[x]-sum[i-1]));//这里没模很可能爆了负数
            }
        }
        int t=((n<=sqr)?id1[n]:id2[1]);
        ll su=((g1[t]-2)%mod+mod)%mod;
        //记住mod求稳
        ll he=(n+3)%mod*((n-2)%mod)%mod*((mod+1)/2)%mod;
        printf("%lld\n",(su+he)%mod);
    }
    return 0;
}
