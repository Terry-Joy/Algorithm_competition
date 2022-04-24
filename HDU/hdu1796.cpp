#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[30];
int prime[30],a[30],i,ans,n,m,num;
const int INF=0x3f3f3f3f;
void init()
{
   int cnt=0; 
   for(int i=2;i<=20;++i)
   {
      if(!v[i])v[i]=i,prime[++cnt]=i;
      for(int j=1;j<=cnt&&prime[j]*i<=20;++j)
      {
         if(prime[j]>v[i])break;
         v[i*prime[j]]=prime[j]; 
      }
   } 
}
void dfs(int pos,int sum,int li)
{
    if(li==0)
    {
        if(i&1)ans+=(n-1/sum);
        else ans-=(n-1/sum);
    }
    if(pos==num+1)return;
    if(sum*a[pos]<n)
        dfs(pos+1,sum*a[pos],li-1);
    dfs(pos+1,sum,li);
    return;
}
int main()
{
   init(); 
   while(~scanf("%d%d",&n,&m))
   {
      ans=0; 
      memset(a,0,sizeof(a));
      bool flag=0;
      for(int i=1;i<=m;++i)
      { 
         scanf("%d",&a[i]); 
         if(a[i]==1)
             flag=1;
         a[i]=v[a[i]];
      }
      if(flag)
      {
         printf("%d\n",n);
         continue; 
      }
     num=unique(a+1,a+1+m)-(a+1);
     for(i=1;i<=num;++i)
        dfs(1,1,i);
     printf("%d\n",ans);
   }
   return 0;
}
