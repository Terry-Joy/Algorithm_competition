#include<bits/stdc++.h>
#define fi first 
#define se second
#define lowb(i) (i&(-i))
using namespace std;
using ll=long long;
using P=pair<ll,int>;
const int maxn=3e4+10;
int n,r,k,p1[maxn],p2[maxn],p3[maxn];
ll a[maxn],b[maxn],c[maxn],sum,num[maxn];
P g[maxn],h[maxn],f[maxn];
ll ask(int x){
	if(x<0)return 0;
    ll ans=0;
    for(int i=x;i;i-=lowb(i))ans+=num[i];
    return ans;
}
void add(int x,ll val){ 
    for(;x<=n;x+=lowb(x))
        num[x]+=val;
}
ll check(ll x){ 
    ll res=0;
    for(int i=n-r+1,j=1;i;--i){ 
        while(j<=n-r+1&&g[i].fi+g[j].fi<=x)
            add(g[j++].se,1);
        res+=ask(g[i].se-r);
    }
    for(int i=1;i<=n;++i)num[i]=0;
    for(int i=n-r+1,j=1;i;--i){ 
        while(j<=n-r+1&&h[j].fi+f[i].fi<=x)
            add(h[j++].se,1);
        res+=ask(f[i].se-1)-ask(f[i].se-r);
    }
    for(int i=1;i<=n;++i)num[i]=0;
    return res;
}
int main(){
    cin>>n>>r>>k;
    for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
    for(int i=1;i<=n;++i)cin>>b[i],b[i]-=a[i];
    for(int i=1;i<=n;++i)cin>>c[i],c[i]-=a[i];
    for(int i=2;i<=n;++i)b[i]+=b[i-1],c[i]+=c[i-1];
    for(int i=1;i+r-1<=n;++i)g[i].fi=b[i+r-1]-b[i-1],g[i].se=i;
    for(int i=1;i+r-1<=n;++i)h[i].fi=c[i+r-1]-b[i-1]-b[i+r-1],h[i].se=i;
    for(int i=1;i+r-1<=n;++i)f[i].fi=b[i-1]-c[i-1]+b[i+r-1],f[i].se=i;
    sort(g+1,g+n-r+2);
    //for(int i=1;i+r-1<=n;++i)cout<<g[i].fi<<" "<<g[i].se<<"\n";
    sort(f+1,f+n-r+2);
    sort(h+1,h+n-r+2);
    ll L=0,R=c[n];
    while(L<R){
        ll mid=L+R>>1;
        if(check(mid)>=k)R=mid;
        else L=mid+1;
    }
    cout<<R+sum;
    return 0;
}

