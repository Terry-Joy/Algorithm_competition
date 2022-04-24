#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const ll mod=1e9+7;
int prime[maxn/10],cnt=0;
bool v[maxn];
ll mypow(ll a,ll b){
   ll ans=1;
   while(b){ 
       if(b&1)ans=ans*a%mod;
       a=a*a%mod;
       b>>=1;  
   } 
   return ans;
}
void init(int maxm)
{
   v[1]=1;
   for(int i=2;i<=maxm;++i){ 
       if(!v[i])prime[++cnt]=i;
       for(int j=1;j<=cnt&&prime[j]*i<=maxm;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
       }
   } 
}
int main()
{
   init(1000000);
   int t,n,c;
   scanf("%d",&t);
   while(t--){ 
       scanf("%d%d",&n,&c);
       int x=0;
       for(int i=1;prime[i]*prime[i]<=n;++i){ 
           if(n%prime[i]==0){ 
              while(n%prime[i]==0)n/=prime[i],x++;  
           } 
       } 
       if(n>1)x++;
       printf("%lld\n",mypow(1ll*c,1ll*x));
   } 
   return 0; 
}
