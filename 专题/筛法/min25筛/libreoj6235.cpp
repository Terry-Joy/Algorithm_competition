#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3.2e5;
const int maxm=3e6+10;
ll n,prime[maxn];
ll sum[maxn],w[maxm],g[maxm];
int cnt,id1[maxn],id2[maxn],sqr,m;
bool v[maxn];
void init(){ 
    v[1]=1;
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=cnt;++i)
        sum[i]=(sum[i-1]+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    init();
    sqr=sqrt(n+0.5);
    for(ll i=1,j;i<=n;i=j+1){ 
        j=(n/(n/i));
        w[++m]=n/i;
        g[m]=w[m];
        g[m]--;
        if(w[m]<=sqr)id1[w[m]]=m;
        else id2[n/w[m]]=m;
    }
    for(int i=1;i<=cnt;++i){ 
        ll pr=prime[i]*prime[i];
        for(int j=1;j<=m&&pr<=w[j];++j){ 
            ll x=w[j]/prime[i];
            x=((x<=sqr)?id1[x]:id2[n/x]);
            g[j]=g[j]-(g[x]-sum[i-1]);
        }
    }
    cout<<g[1]<<"\n";
    return 0;
}
