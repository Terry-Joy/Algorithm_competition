#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,x,m;
const int maxn=1e5+5;
bool v[maxn];
int a[maxn],sum[maxn];
ll S(ll a){
    return a*a%m;
}
int main(){
    scanf("%lld%lld%lld",&n,&x,&m);
    int cnt=1;
    v[x]=1;a[x]=1;sum[cnt]=x;
    for(int i=2;i<=10000000;++i){
        x=S(x);
        if(!v[x])v[x]=1,a[x]=i,sum[++cnt]=x;
        else break;
    }
    ll ans=0;
    for(int i=1;i<=a[x]-1;++i)ans+=(sum[i]);
    ll t=0;
    for(int i=a[x];i<=cnt;++i)t+=sum[i];
    n-=(a[x]-1);
    ans+=(t*(n/(cnt-a[x]+1)));
    ll k=(n%(cnt-a[x]+1));
    for(int i=a[x];i<=a[x]+k-1;++i)
        ans+=sum[i];
    cout<<ans<<endl;
    return 0;
}