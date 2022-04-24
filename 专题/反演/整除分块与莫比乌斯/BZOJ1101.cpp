#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e4+5;
int prime[maxn/10],mu[maxn],sum[maxn],cnt=0;
bool v[maxn];
void init()
{
    v[1]=mu[1]=1;sum[1]=1;
    int k=maxn-5;
    for(int i=2;i<=k;++i)
    {
       if(!v[i])prime[++cnt]=i,mu[i]=-1;
       for(int j=1;j<=cnt&&prime[j]*i<=k;++j)
       {
          v[i*prime[j]]=1;
          if(i%prime[j]==0){
          	mu[i*prime[j]]=0;break;
		  }
          else mu[i*prime[j]]=-mu[i];
       } 
       sum[i]=sum[i-1]+mu[i];
    }
}
int main()
{
   int t;
   init();
   scanf("%d",&t);
   while(t--)
   {
      int a,b,d;
      scanf("%d%d%d",&a,&b,&d);
      if(a>b)swap(a,b);
      a/=d,b/=d;
      int l=1,r=0;
	  int ans=0;
      for(int l=1;l<=a&&(a/l);l=r+1)
      {
          r=min(a/(a/l),b/(b/l));
          ans+=(1ll*(sum[r]-sum[l-1])*(a/l)*(b/l));  
      } 
      printf("%d\n",ans);
   } 
   return 0; 
}
