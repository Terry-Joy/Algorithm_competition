#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+10;
ll dp[maxn][15];
ll a[maxn];
const ll INF=1e18;
int main()
{
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);
   for(int i=1;i<=n;++i) 
       scanf("%lld",&a[i]);
   for(int i=0;i<=n;++i)
       for(int j=0;j<=10;++j)
           dp[i][j]=-INF;
   dp[0][m-1]=0;
   ll ans=0;
   for(int i=1;i<=n;++i)
   {
      for(int j=0;j<=m-1;++j)
      {
         if(j==0)
             dp[i][j]=max(dp[i-1][m-1]+a[i]-k,a[i]-k);
         else
             dp[i][j]=dp[i-1][j-1]+a[i];
         ans=max(ans,dp[i][j]);
      } 
   }
   printf("%lld\n",ans);
   return 0; 
}
