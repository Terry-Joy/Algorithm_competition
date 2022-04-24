#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int mu[maxn],prime[maxn],cnt=0;
bool v[maxn];
void init()
{
   mu[1]=v[1]=1;
   for(int i=2;i<=maxn-4;++i){ 
        if(!v[i])prime[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-4;++j)
        {
           v[i*prime[j]]=1;
           if(i%prime[j]==0)break;
           else mu[i*prime[j]]=-mu[i]; 
        }
   }
}
int main()
{
   init(); 
   int n,m;
   ll ans=0;
   scanf("%d%d",&n,&m);
   if(n>m)swap(n,m);    
   for(int d=1;d<=n;++d)
      for(int k=d;k<=n;k+=d)
          ans+=1ll*mu[k/d]*(n/k)*(m/k)*d;
   ans=ans*2-1ll*n*m;
   printf("%lld",ans);
   return 0; 
}
