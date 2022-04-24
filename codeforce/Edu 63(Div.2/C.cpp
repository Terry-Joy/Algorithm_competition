#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=3e5+10;
ll a[maxn],b[maxn];
ll gcd(ll a,ll b)
{
   return b?gcd(b,a%b):a; 
}
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i)
       scanf("%lld",&a[i]);
   for(int j=1;j<=m;++j)
       scanf("%lld",&b[j]);
   for(int i=2;i<=n;++i)
       a[i]-=a[1];
   ll gm=gcd(a[2],a[3]);
   for(int i=4;i<=n;++i)
       gm=gcd(gm,a[i]);
   for(int i=1;i<=m;++i)
       if(gm%b[i]==0)
       {
          puts("YES");
          printf("%lld %d\n",a[1],i);
          return 0; 
       }
   puts("NO");
   return 0; 
}
