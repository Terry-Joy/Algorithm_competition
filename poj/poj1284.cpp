#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=65539;
int phi[maxn],prime[maxn],cnt=0;
bool v[maxn];
void init()
{
   v[1]=v[0]=1;phi[1]=1;
   for(int i=2;i<=maxn-3;++i)
   {
      if(!v[i])phi[i]=i-1,prime[++cnt]=i;
      for(int j=1;j<=cnt&&prime[j]*i<=maxn-3;++j)
      {
         v[i*prime[j]]=1; 
         if(i%prime[j]==0)
         {
            phi[i*prime[j]]=phi[i]*prime[j];
            break;
         } 
         else phi[i*prime[j]]=phi[i]*(prime[j]-1);
      } 
   } 
}
int main()
{
   init();
   int n;
   while(~scanf("%d",&n))
       printf("%d\n",phi[n-1]);
   return 0; 
}
