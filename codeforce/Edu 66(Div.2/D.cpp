#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+10;
ll a[maxn],sum[maxn];
int main()
{
   int n,k;
   scanf("%d%d",&n,&k);
   for(int i=1;i<=n;++i)
       scanf("%lld",&a[i]);
   for(int i=2;i<=n;++i)
      a[i]+=a[i-1];
   ll ans=0;
   ans+=k*a[n];
   sort(a+1,a+n);
   for(int i=1;i<=k-1;++i)
      ans-=a[i];
   printf("%lld\n",ans); 
   return 0; 
}
