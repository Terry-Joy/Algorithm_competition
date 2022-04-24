#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int mod=998244353;
const int maxn=5010;
ll dp[maxn][maxn],inv[maxn],s[maxn];
void init()
{
   inv[1]=1;
   for(int i=2;i<maxn;++i)
      inv[i]=(mod-mod/i)*inv[mod%i]%mod;
   for(int i=0;i<maxn;++i)
      dp[0][i]=1; 
}
int main()
{
   init();
   ll n,ans=0;
   scanf("%lld",&n);
   for(int i=1;i<=n;++i)
   {
      int a;
      scanf("%d",&a);
      s[a]++; 
   }
   for(int i=1;i<=n;++i)
   {
      ll num=0;
      for(int j=1;j<=n;++j)
      {
         ll sum=dp[i-1][j-1]*s[j]%mod*inv[n-i+1]%mod;
         num=(num+sum)%mod;
         dp[i][j]=num; 
         if(s[j]>=2)ans=(ans+sum*(s[j]-1)%mod*inv[n-i]%mod)%mod;
      } 
   }
   cout<<ans<<"\n";
   return 0; 
}
