#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
const ll mod=998244353;
int l[maxn],r[maxn],mx[maxn<<1],L,R;
ll fac[maxn],facinv[maxn],ans=0;
vector<pair<int,int>>a;
priority_queue<int,vector<int>,greater<int>>q;
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod;
    facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        facinv[i]=facinv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
    return fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
int main(){ 
    init();
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&L,&R);
        a.push_back({L,R});
    } 
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();++i){
        while(!q.empty()&&q.top()<a[i].first)q.pop();
        if(q.size()>=k-1)
            ans=(ans+C(q.size(),k-1))%mod;
        q.push(a[i].second);
    }
    cout<<ans<<endl;
    return 0;
}
