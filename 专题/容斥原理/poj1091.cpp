#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5;
int n,m,prime[maxn],cnt,j;
ll num;
ll mypow(ll a,ll b)
{
   ll ans=1;
   while(b){ 
      if(b&1)ans=ans*a;
      a=a*a;
      b>>=1;
   } 
   return ans;
}
void dfs(int pos,int sum,int li)
{
   if(!li)
   {
      if(j&1)num-=mypow((m/sum),n);
      else num+=mypow((m/sum),n); 
      return;
   } 
   if(pos==cnt+1)return;
   if(prime[pos]*sum<=m)
       dfs(pos+1,prime[pos]*sum,li-1);
   dfs(pos+1,sum,li);
}
int main()
{
   cnt=0;
   scanf("%d%d",&n,&m);
   num=mypow(m,n);
   int k=m;
   for(int i=2;i*i<=k;++i)
   {
      if(k%i==0)
      { 
         prime[++cnt]=i; 
         while(k%i==0)k/=i;
      }
   }
   if(k>1)prime[++cnt]=k;
   for(j=1;j<=cnt;++j)
      dfs(1,1,j); 
   printf("%lld\n",num);
   return 0; 
}

