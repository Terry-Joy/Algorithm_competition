#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e7+7;
const int maxn=1e6+10;
ll prime[maxn],cnt;
bool vis[maxn];
void primes()
{
   memset(vis,0,sizeof(vis));
   for(int i=2;i<maxn;++i)
   {
       if(!vis[i])prime[++cnt]=i;
       for(int j=1;j<=cnt&&prime[j]*i<=maxn;++j)
       {
          vis[prime[j]*i]=1;
          if(i%prime[j]==0)break; 
       }
   } 
}
ll s(ll n,ll m)
{
   ll ans=0;
   while(n)
   {
      ans+=n/m;
      n/=m; 
   } 
   return ans;
}
int main()
{
   primes();
   int n;
   while(scanf("%d",&n)&&n)
   {
      ll ans=1;
      for(int i=1;prime[i]<=n;++i)
        {
           ll sum=s(n,prime[i]);
           ans=ans%mod*(ll)(sum+1)*(sum+2)/2%mod; 
        } 
      printf("%lld\n",ans);
   }
   return 0; 
}
