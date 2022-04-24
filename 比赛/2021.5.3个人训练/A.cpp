#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+105;
ll dp[maxn];
int n,q,k,a[maxn];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%lld",&dp[i]);
    for(int i=n+1;i<=10000+100;++i){
        dp[i]=9e18;
        for(int j=1;j<=n;++j){
            dp[i]=min(dp[i],dp[i-j]+dp[j]);
        }
    }
    int now=1;
    for(int i=2;i<=n;++i){
        if(dp[i]*now<dp[now]*i)
            now=i;
    }
    while(q--){
        scanf("%d",&k);
        if(k<=10000){
            cout<<dp[k]<<"\n";
        }else{
            ll sum=(k-10000)/now;
            ll x=sum*dp[now];
            k-=sum*now;
            cout<<x+dp[k]<<"\n";
        }
    }
    return 0;
}