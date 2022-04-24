#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=998244353;
int c,f[maxn],b[maxn],n,a[maxn];
vector<int>g[maxn];
void add(int&x,int y){ x+=y;if(x>=mod)x-=mod;}
int mul(ll x){ 
    return (x>=mod)?x%mod:x;
}
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)f[i]=mypow(i,c);
    for(int i=1;i<=n;++i){ 
        g[i].pb(0);
        int sum=0;
        for(int j=1;(ll)i*j<=n;++j){ 
            add(sum,mul((ll)a[i*j]*f[j]));
            g[i].pb(sum);
        }
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;(ll)i*j<=n;++j){ 
            if(__gcd(i,j)>1)continue;
            int m=min(n/i,n/j);
            add(b[i*j],mul((ll)f[j]*g[i][m]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans^=b[i];
    cout<<ans;
    return 0;
}
