#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int dp[maxn],a[maxn];
int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
       for(int i=1;i<=n;++i)
          dp[i]=1;
       int k=n/2;
       for(int i=1;i<=n;++i)
          for(int j=2*i;j<=n;j+=i)
             if(a[j]>a[i])dp[j]=max(dp[j],dp[i]+1);
      int ans=0;
      for(int i=1;i<=n;++i)
         ans=max(ans,dp[i]);
      printf("%d\n",ans); 
   }
   return 0; 
}
