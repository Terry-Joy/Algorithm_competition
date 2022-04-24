#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[360],a[360];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   { 
       for(int j=1;j<=i;++j)
           scanf("%d",&a[j]);
       for(int j=i;j>=1;--j)    //滚动数组减少拷贝操作 倒序保证由i-1转移到i
       {
           dp[j]=max(dp[j],dp[j-1])+a[j];
       }
   }
   int ans=-1;
   for(int i=1;i<=n;++i)
       ans=max(ans,dp[i]);
   printf("%d\n",ans);
   return 0; 
}
