#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[3];
const ll INF=-1*0x3f3f3f3f3f3f3f3f;
int main()
{
   int n;
   ll a,k,ans=INF;
   scanf("%d%lld",&n,&k);
   for(int i=1;i<=n;++i)
   {
      scanf("%lld",&a); 
      dp[0]=max(0ll,dp[0]+a);
      dp[1]=max(dp[0],dp[1]+k*a);
      dp[2]=max(dp[1],dp[2]+a);
      ans=max(ans,dp[2]);
   }
   printf("%lld",ans);
   return 0; 
}
