#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<string>
#include<map>
#define ll long long
using namespace std;
const int maxn=1e6+10;
ll dp[maxn];
ll top,d,h,ans=0,hi[3];
ll ask(ll i,ll hi)
{
   return (top+(d-top)*(h-i)*1.0/h)/hi; 
}
int main()
{
    while(~scanf("%lld%lld%lld%lld%lld%lld",&h,&d,&top,&hi[0],&hi[1],&hi[2]))
    {
       memset(dp,-1,sizeof(dp));
       dp[0]=0;ans=0;
       for(ll i=1;i<=h;++i)
       {
          for(ll j=0;j<3;++j)
          {
             if(i<hi[j]||dp[i-hi[j]]==-1)continue;
             ll width=ask(i,hi[j]);
             dp[i]=max(dp[i],dp[i-hi[j]]+width*width*hi[j]*hi[j]*hi[j]); 
          } 
          ans=max(ans,dp[i]);
       } 
       printf("%lld\n",ans);
    }
    return 0;
}
