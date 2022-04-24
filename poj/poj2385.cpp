#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[2][35],a[1010];

int main()
{
   int t,w; 
   scanf("%d%d",&t,&w);
   for(int i=1;i<=t;++i)
       scanf("%d",&a[i]);
   for(int i=1;i<=t;++i)
   {
       dp[i&1][0]=dp[(i-1)&1][0]+(a[i]==1); 
       for(int j=1;j<=min(i,w);++j)
       {
                  dp[i&1][j]=max(dp[(i-1)&1][j-1],dp[(i-1)&1][j])+((j%2+1)==a[i]);
       }
   }
   int ans=-1;
   for(int i=0;i<=w;++i)
       ans=max(ans,dp[t&1][i]);
   printf("%d",ans);
   return 0; 
}
