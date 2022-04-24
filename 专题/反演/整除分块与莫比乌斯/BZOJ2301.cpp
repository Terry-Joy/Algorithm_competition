#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int mu[maxn+50],prime[maxn+50],cnt=0;
int sum[maxn+50];
int a,b,c,d,k;
bool v[maxn];
void init(int n)
{
   mu[1]=v[1]=1;
   for(int i=2;i<=n;++i)
   {
      if(!v[i])prime[++cnt]=i,mu[i]=-1;
      for(int j=1;j<=cnt&&prime[j]*i<=n;++j)
      {
         v[i*prime[j]]=1;
         if(i%prime[j]==0)break;
         else mu[i*prime[j]]=-mu[i]; 
      } 
   }
   for(int i=1;i<=n;++i)
       sum[i]=sum[i-1]+mu[i];
}
ll solve(int x2,int y2){ 
    x2/=k,y2/=k;
    int m=min(x2,y2);
    ll ans=0;
    int l=1,r=0;
    for(int l=1;l<=m&&(x2/l)&&(y2/l);l=r+1){ 
        r=min(x2/(x2/l),y2/(y2/l));
        ans+=1ll*(sum[r]-sum[l-1])*(x2/l)*(y2/l);
    }
    return ans;
}
int main()
{
   init(50000); 
   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
       printf("%lld\n",solve(b,d)-solve(b,c-1)-solve(a-1,d)+solve(a-1,c-1));
   } 
   return 0; 
}
