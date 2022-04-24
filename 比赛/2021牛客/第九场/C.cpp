#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const int maxn=(1<<22);
const int M=1e6;
ll fac[maxn],a[maxn],b[maxn],ans,w[maxn];
int n,tr[maxn];
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void NTT(ll *a,int n,bool f){ 
    for(int i=1;i<n;++i){ 
        tr[i]=(tr[i>>1]>>1)+(i&1)*(n>>1);
        if(i<tr[i])swap(a[i],a[tr[i]]);
    }
    ll x;
    for(int p=1;p<n;p<<=1)
        for(int k=0;k<n;k+=2*p){ 
            for(int l=0;l<p;++l){ 
                x=a[p+k+l]*w[p+l]%mod;
                a[p+k+l]=(a[k+l]-x+mod)%mod;
                a[k+l]+=x;
                a[k+l]%=mod;  
            }
        }
    if(f){ 
        reverse(a+1,a+n);
        x=mypow(n,mod-2);
        for(int i=0;i<n;++i){ 
            a[i]=a[i]*x%mod;
        }
    }
}
void init(){ 
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*i%mod;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans=1;
    cin>>n;
    int a_i;
    init();
    for(int i=1;i<=n;++i){ 
        cin>>a_i;
        a[a_i]++;b[M-a_i]++;
        ans=ans*(a_i+1)%mod;
    }
    ll x=mypow(fac[n],mod-2);
    for(int i=n;i>=1;--i){ 
        ans=ans*x%mod;
        x=x*i%mod;
    }
    int v=maxn/2;
    for(int i=1;i<v;i<<=1){ 
        w[i]=1;
        ll x=mypow(3,(mod-1)/2/i);
        for(int j=1;j<i;++j)
            w[i+j]=w[i+j-1]*x%mod;
    }
    NTT(a,v,0);
    NTT(b,v,0);
    for(int i=0;i<v;++i){ 
        a[i]=a[i]*b[i]%mod;
    }
    NTT(a,v,-1);
    for(int i=M+1;i<=2*M;++i){ 
        if(a[i]){ 
            ans=(ans*mypow((i-M+mod)%mod,a[i])%mod);
        }
    }
    cout<<ans;
}
