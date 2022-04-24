#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int mu[40007],prime[40007],cnt=0,k;
bool v[40007];
ll ans;
int sum[40007];
void init()
{ 
    mu[1]=v[1]=1;
    sum[1]=1;
    for(int i=2;i<=40005;++i)
    {
       if(!v[i])prime[++cnt]=i,mu[i]=-1;
       for(int j=1;j<=cnt&&prime[j]*i<=40005;++j)
       {
          v[i*prime[j]]=1;
          if(i%prime[j]==0){ mu[i*prime[j]]=0;break;}
          else mu[i*prime[j]]=-mu[i]; 
       }
       sum[i]=sum[i-1]+mu[i]; 
    }
}
bool check(int mid)
{
    int l=1,r=0;
    ll ans=0;
    for(int l=1;l*l<=mid;l=r+1){ 
        r=min((int)sqrt(mid/(mid/(l*l))),mid);
        ans+=1ll*(sum[r]-sum[l-1])*(mid/(l*l));
    }
    return ans>=k;
}
int main()
{
   init();
   int t;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&k);
      ll l=k,r=2*k;
      while(l<r)
      {
         ll mid=l+r>>1;
         if(check(mid))
             r=mid;
         else l=mid+1;
      } 
      printf("%d\n",r);
   } 
   return 0; 
}
