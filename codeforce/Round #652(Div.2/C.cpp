#include<bits/stdc++.h>
#define pb push_back
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
bool v[maxn];
ll a[maxn],w[maxn],vis[maxn];
bool cmp(ll x,ll y)
{
   return x>y; 
}
int main()
{
   int t,n,k;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&n,&k);
      for(int i=1;i<=n;++i)
          scanf("%lld",&a[i]);
      for(int i=1;i<=k;++i)
          scanf("%lld",&w[i]);
      sort(a+1,a+1+n,cmp);
      sort(w+1,w+1+k);
      ll ans=0;
      for(int i=1;i<=k;++i)
          ans+=a[i];
      ans+=a[n];
      int f=k;
      for(int i=1;i<k;++i)
      {
         if(w[i]==1)ans+=a[i];
         else
         {
             ans+=a[f+w[i]-1];
             f=f+w[i]-1;    
         } 
      }   
      printf("%lld\n",ans);
   }  
   return 0; 
}
