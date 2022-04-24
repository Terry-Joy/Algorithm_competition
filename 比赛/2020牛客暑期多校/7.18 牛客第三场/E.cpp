#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll dp[maxn],ans;
int a[maxn];
int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
       ans=0;
       scanf("%d",&n);
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
       sort(a+1,a+1+n);
       for(int i=1;i<=n;i+=2)
           ans+=1ll*(a[i+1]-a[i]);
       for(int i=1;i<=n;++i)
          dp[i]=0x3f3f3f3f3f3f3f3fll;
       dp[0]=0;
       for(int i=1;i<=n;i+=2){ 
           if(i>=3) 
               dp[i+1]=min(dp[i+1],dp[i-3]+a[i+1]-a[i-1]+a[i]-a[i-2]);
           if(i>=5)
               dp[i+1]=min(dp[i+1],dp[i-5]+a[i+1]+a[i]+a[i-2]-a[i-1]-a[i-3]-a[i-4]);
       }
       ans+=dp[n];
       printf("%lld\n",ans);
   } 
   return 0; 
}
