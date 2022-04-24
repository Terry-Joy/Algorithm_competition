#include<bits/stdc++.h>
#define lowb(x) (x&(-x))
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const ll mod=998244353;
int n,pi,c[maxn],a[maxn],pre[maxn],sum;
ll fac[maxn];
void add(int x,int val){
    for(int i=x;i<=n;i+=lowb(i)){
        c[i]+=val;
    }
}
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int ask(int x){
    int ans=0;
    for(int i=x;i;i-=lowb(i)){
        ans+=c[i];
    }
    return ans;
}
int main(){
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        if(a[i]!=-1){
            ans+=ask(n)-ask(a[i]);
            add(a[i],1);
        }else{
            sum++;
        }
        pre[i]=pre[i-1]+(a[i]==-1);
        if(ans>=mod)ans-=mod; 	
    }
    ll inv=mypow(sum,mod-2);
    fac[1]=1;
    for(int i=2;i<=sum;++i)fac[i]=fac[i-1]*i%mod;
    ll ans1=1ll*sum*(sum-1)%mod*mypow(4,mod-2)%mod;
    ans=(ans+ans1)%mod;
    for(int i=1;i<=n;++i){
        if(a[i]!=-1){
            int cnt=ask(n)-ask(a[i]);
            ll x1=1ll*pre[i]*(n-a[i]-cnt)%mod*inv%mod;
            int cnt2=ask(a[i]-1);
            ll x2=1ll*(sum-pre[i])*(a[i]-1-cnt2)%mod*inv%mod;
            ans=(ans+x1+x2)%mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}