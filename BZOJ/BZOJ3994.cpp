#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int mu[maxn],prime[maxn],cnt=0;
ll sum[maxn],g[maxn];
bool v[maxn];
void init()
{
   mu[1]=v[1]=sum[1]=1;
   for(int i=2;i<=maxn-5;++i)
   {
      if(!v[i])prime[++cnt]=i,mu[i]=-1;
      for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j)
      {
          v[i*prime[j]]=1;
          if(i%prime[j]==0){ mu[i*prime[j]]=0;break;}
          else mu[i*prime[j]]=-mu[i];  
      } 
   } 
   for(int i=2;i<=maxn-5;++i)
       sum[i]=sum[i-1]+mu[i];
   int r;
   for(int i=1;i<=maxn-5;++i)
   { 
      for(int l=1;l<=i;l=r+1)
      {
         r=(i/(i/l));
         g[i]+=1ll*(r-l+1)*(i/l);
      } 
   }
}
int main()
{
   init(); 
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if(n>m)swap(n,m);
      int l=1,r=0;
      ll ans=0;
      for(int l=1;l<=n;l=r+1)
      {
         r=min(n/(n/l),m/(m/l)); 
         ans+=(sum[r]-sum[l-1])*g[n/l]*g[m/l];
      } 
      printf("%lld\n",ans);
   } 
   return 0; 
}
