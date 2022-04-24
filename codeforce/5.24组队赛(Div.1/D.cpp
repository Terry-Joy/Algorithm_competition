#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
int n,mx,a[maxn],cnt[maxn],b[maxn],t;
ll inv[maxn];
void init()
{
   inv[0]=inv[1]=1;
   for(int i=2;i<maxn;++i)
      inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod; 
}

int solve(int gcd)
{
   ll sum=0,ans=0;
   for(int i=gcd;i<=mx;i+=gcd)
    sum=(sum%mod+cnt[i]*1ll*i%mod)%mod;
    if(gcd==2)
    	cout<<sum<<endl;
   for(int i=gcd;i<=mx;i+=gcd)
      ans=(ans%mod+cnt[i]*1ll*i%mod*sum%mod)%mod;
   if(gcd==2)
   	  cout<<ans<<endl;
   ans=(ans*inv[gcd])%mod;
   if(gcd==2)
   	  cout<<ans<<endl;
   for(int i=2*gcd;i<=mx;i+=gcd)
   {
     ans-=b[i]*1ll*i%mod*inv[gcd]%mod;
      if(ans<0)
         ans+=mod; 
   } 
   if(gcd==2)
   		cout<<ans<<endl;
   	if(gcd==4)
   		cout<<ans<<endl;
   return b[gcd]=ans;
}

typedef long long ll;

int main()
{
   init();
   scanf("%d",&t);
   while(t--)
   {
      mx=0;
      scanf("%d",&n);
      memset(cnt,0,sizeof(cnt));
      memset(b,0,sizeof(b));
      for(int i=0;i<n;++i)
      {
         scanf("%d",&a[i]);
         cnt[a[i]]++;
         mx=max(mx,a[i]); 
      } 
      int num=0;
      for(int k=mx;k>=1;k--)
      {
         num=(num%mod+solve(k))%mod; 
      }
      printf("%d\n",num);
   }
   return 0; 
}
