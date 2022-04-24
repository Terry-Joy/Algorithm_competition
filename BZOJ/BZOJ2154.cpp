#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const ll mod=20101009;
const int maxn=1e7+5;
int n,m,prime[maxn/10+5],mu[maxn],cnt;
ll sum[maxn];
bool v[maxn];
void init(int maxm)
{
   v[1]=mu[1]=1;
   for(int i=2;i<=maxm;++i){ 
       if(!v[i])prime[++cnt]=i,mu[i]=-1;
       for(int j=1;j<=cnt&&prime[j]*i<=maxm;++j){ 
           v[i*prime[j]]=1;
           if(i%prime[j]==0)break;
           else mu[i*prime[j]]=-mu[i]; 
       }
   }  
   for(int i=1;i<=maxm;++i)
       sum[i]=(sum[i-1]+1ll*i*i%mod*(mu[i]+mod))%mod;//莫比乌斯取负数
}
ll S(int n,int m)
{
    ll ans=(1ll*(n+1)*n/2%mod)*(1ll*(m+1)*m/2%mod)%mod;
    return ans;
}
ll G(int n,int m)
{
   ll ans=0;
   int l,r;
   for(l=1;l<=n&&(n/l);l=r+1){ 
       r=min(n/(n/l),m/(m/l));
       ans=(ans+1ll*(sum[r]-sum[l-1]+mod)%mod*S(n/l,m/l)%mod)%mod; 
   } 
   return ans;
}
int main()
{
   scanf("%d%d",&n,&m);
   if(n>m)swap(n,m); 
   init(n);
   int l,r;
   ll ans=0;
   for(l=1;l<=n;l=r+1){ 
      r=min(n/(n/l),m/(m/l));//注意不能只(n/(n/l)) 因为要保证第二个求和
      ans=(ans+1ll*(r-l+1)%mod*(r+l)/2%mod*G(n/l,m/l)%mod)%mod;  
   }
   printf("%lld\n",ans);
   return 0; 
}
