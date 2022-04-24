#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e5+3;
ll dp[2][maxn][2],w1[maxn],w2[maxn],a,b;
int prime[maxn],phi[maxn],cnt,v1[maxn],v2[maxn],n,m;
bool v[maxn];
void init(){
    v[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
ll Mod(ll n,ll m){
    return n<m?n:(n%m+m);
}
ll mypow(ll a,ll b,ll m1){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%m1;
        a=a*a%m1;b>>=1;
    }
    return ans;
}
ll solve(int num,ll mo,ll tt){
    if(num==1||mo==1)return Mod(tt,mo);
    return mypow(tt,solve(num-1,phi[mo],tt)+phi[mo],mo);
}

int main(){
    init();
    scanf("%lld%lld",&a,&b);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&v1[i]);
    for(int i=1;i<=n;++i)scanf("%d",&v2[i]);
    for(int i=1;i<=n;++i)
        w1[i]=mypow(a,solve(v1[i],mod-1,b)+mod-1,mod);
    for(int i=1;i<=n;++i)
        w2[i]=mypow(a,solve(v2[i],mod-1,b)+mod-1,mod);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
             dp[i&1][j][0]=dp[i&1][j][1]=0;
             if(w1[i]==w2[j]){
                 dp[i&1][j][0]=max(dp[i&1][j][0],dp[(i-1)&1][j][1]+w1[i]);
                 dp[i&1][j][1]=max(dp[i&1][j][1],dp[i][j-1][0]+w2[j]);
             }else{
                 dp[i&1][j][0]=max(dp[i&1][j][0],dp[(i-1)&1][j][1]);
                 dp[i&1][j][1]=max(dp[i&1][j][1],dp[i][j-1][0]);
             }
             if(w1[i]==w1[i-1]){
                 dp[i&1][j][0]=max(dp[i&1][j][0],dp[(i-1)&1][j][0]+w1[i]);
             }else{
                 dp[i&1][j][0]=max(dp[i&1][j][0],dp[(i-1)&1][j][0]);
             }
             if(w2[j]==w2[j-1]){
                 dp[i&1][j][1]=max(dp[i&1][j][1],dp[i&1][j-1][1]+w2[j]);
             }else{
                 dp[i&1][j][1]=max(dp[i&1][j][1],dp[i&1][j-1][1]);
             }
        }
    }
    cout<<max(dp[n&1][n][0],dp[n&1][n][1])<<endl;
}