#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const int maxm=1e6+5;
int prime[maxm],mu[maxn],cnt=0;
ll sum[maxn];
bool v[maxn];
void init()
{
   v[1]=mu[1]=1;
   for(int i=2;i<=maxn-5;++i)
   {
      if(!v[i])prime[++cnt]=i,mu[i]=-1,sum[i]=1;
      for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j)
      {//线性筛
         v[i*prime[j]]=1;
         if(i%prime[j]==0)
         {
            mu[i*prime[j]]=0;
            sum[i*prime[j]]=mu[i]; 
            break;
         } 
         else mu[i*prime[j]]=-mu[i],sum[i*prime[j]]=-sum[i]+mu[i];
      }
      sum[i]+=sum[i-1];
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
       for(l=1;l<=n;l=r+1)
       {
          r=min(n/(n/l),m/(m/l));
          ans+=(sum[r]-sum[l-1])*(n/l)*(m/l); 
       }
       printf("%lld\n",ans);
   } 
   return 0; 
}
